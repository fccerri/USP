import pandas as pd

class Aluno:
    def __init__(self, dados):
        self.nome = dados[0]
        self.email = dados[1]
        self.senha = dados[2]

class View:
    def __init__(self):
        pass
    
    def menu(self):
        print("--------------")
        print("Bem vindo ao sistema de gerenciamento de diciplinas")
        print("1 - Cadastro")
        print("2 - Login")
        print("3 - Recuperar Senha")

        while(True):
            opcao = input("Digite sua opcao (1, 2 ou 3): ")

            if(opcao == '1'):
                return "Cadastro"
            elif(opcao == '2'):
                return "Login"
            elif(opcao == '3'):
                return "Recu_Senha"
            else:
                print("Opcao invalida!")
    
    def get_dados(self):
        nome = input("Digite seu nome: ")
        email = input("Digite seu email: ")
        senha = input("Digite sua senha: ")

        return [nome, email, senha]
    
    def tela_inicial(self, aluno):
        print("--------------")
        print(f"Olá, {aluno.nome}!")
        input("Pressione Enter para fazer Logout...")
    
    def dados_incorretos(self):
        print("--------------")
        print("Dados Incorretos!")
        
        print("1 - Voltar ao Menu")
        print("2 - Tentar novamente")
        while(True):
            opcao = input("Digite sua opcao (1 ou 2): ")

            if(opcao == '1'):
                return True
            elif(opcao == '2'):
                return False
            else:
                print("Opcao invalida!")
    
    def get_email(self):
        return input("Digite seu email: ")
    
    def get_senha(self):
        return input("Digite sua nova senha: ")
    
    def email_ja_cadastrado(self):
        print("Email ja cadastrado! Tente outro")


class Controller:
    def __init__(self):
        pass

    def cria_aluno(self, dados: list):
        return Aluno(dados)
    
    def verifica_email(self, email, model):
        dados = model.acha_aluno(email)

        if(dados != None):
            return self.cria_aluno(dados)
        else:
            return None
    
    def verifica_aluno(self, dados, model):
        dados_achados = model.acha_aluno(dados[1])

        if(dados_achados == None):
            return None
        
        if(dados_achados[2] == dados[2]):
            if(dados_achados[0] == dados[0]):
                return self.cria_aluno(dados_achados)
        
    

class Model:
    def __init__(self, banco_de_dados):
        self.df = pd.read_csv(banco_de_dados)
        self.df = self.df[0:0]
        self.df.to_csv(banco_de_dados, index=False)
    
    def acha_aluno(self, email):
        linha = self.df.loc[self.df['Email'] == email]
        if linha.empty:
            return None
        
        return linha[['Nome', 'Email', 'Senha']].iloc[0].tolist()
    
    def insere_aluno(self, aluno):
        self.df.loc[len(self.df)] = [aluno.nome, aluno.email, aluno.senha]
        self.df.to_csv("banco_de_dados.csv", index=False)
    
    def muda_senha(self, aluno, senha):
        self.df.loc[self.df['Email'] == aluno.email, 'Senha'] = senha
        self.df.to_csv("banco_de_dados.csv", index=False)


                

def main():
    view = View()
    controller = Controller()
    model = Model("./banco_de_dados.csv")

    opcao = view.menu()

    while(True):
        if(opcao == "Menu"):
            opcao = view.menu()

        elif(opcao == "Cadastro"):
            print("--------------\nCadastro")
            dados = view.get_dados()

            #Verifica se esse email ja foi cadastrado
            aluno = controller.verifica_email(dados[1], model)
            if(aluno != None):
                view.email_ja_cadastrado()
                continue

            aluno = controller.cria_aluno(dados)

            model.insere_aluno(aluno)
            opcao = "Login"

        elif(opcao == "Login"):
            print("--------------\nLogin")
            dados = view.get_dados()

            aluno = controller.verifica_aluno(dados, model)
            
            if(aluno != None):
                view.tela_inicial(aluno)

                opcao = "Menu"
            else:
                mudar = view.dados_incorretos()
                if(mudar == True):
                    opcao = "Menu"
        elif(opcao == "Recu_Senha"):
            print("--------------\nRecuperar Senha")
            email = view.get_email()

            aluno = controller.verifica_email(email, model)

            if(aluno != None):
                senha = view.get_senha()

                model.muda_senha(aluno, senha)

                opcao = "Login"
            else:
                mudar = view.dados_incorretos()
                if(mudar == True):
                    opcao = "Menu"

if __name__ == "__main__":
    main()