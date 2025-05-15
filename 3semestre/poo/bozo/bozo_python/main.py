from random import Random

NRODADAS = 10

def main():
    random_seed = int(input("Digite a semente (zero para aleatório): "))

    rd = RolaDados(5, random_seed)
    pl = Placar()
    print(pl)

    for rodada in range(NRODADAS):
        print(f"****** Rodada {rodada+1}")
        print("Pressione ENTER para lançar os dados")
        input()

        #Primeira tentativa
        rd.rolar([True,True,True,True,True])
        print("1          2          3          4          5")
        print(rd)

        #Segunda Tentativa
        print("Digite os números dos dados que quiser TROCAR. Separados por espaços.")
        muda = EntradaTeclado.leString()
        valores = rd.rolar_str(muda)
        print("1          2          3          4          5")
        print(rd)

        #Terceira Tentativa
        print("Digite os números dos dados que quiser TROCAR. Separados por espaços.")
        muda = EntradaTeclado.leString()
        valores = rd.rolar_str(muda)
        print("1          2          3          4          5")
        print(rd)

        print("\n\n")
        print(pl)

        pos = 0
        while( pos <= 0 ):
            try:
                pos = int(input("Escolha a posição que quer ocupar com essa jogada ===> "))
                if( pos > NRODADAS or pos <= 0 ):
                    pos = 0
                pl.add(pos, valores)
            except:
                pos = 0
            if( pos == 0 ):
                print("Valor inválido. Posição ocupada ou inexistente.")
        
        print("\n\n")
        print(pl)
    
    print("***********************************")
    print("***")
    print("*** Seu escore final foi: " + str(pl.getScore()))
    print("***")
    print("***********************************")


class Dado():
    def __init__(self, n=6, seed=0):
        self.r = Random(seed)
        self.lados = n
        if(seed != 0):
            self.r.seed(seed)
        
        self.rolar()
    
    def rolar(self):
        self.atual = self.r.randint(1,6)
        return self.atual
    
    def getLado(self):
        return self.atual
    
    def __str__(self):
        if(self.lados != 6):
            return "Não há representação para esse dados"
        s = "+-----+\n"

        s010 = "|  *  |\n"
        s100 = "|*    |\n"
        s001 = "|    *|\n"
        s000 = "|     |\n"
        s101 = "|*   *|\n"
        s111 = "|* * *|\n"

        match self.getLado():
            case 1:
                s += s000 + s010 + s000
            case 2:
                s += s100 + s000 + s001
            case 3:
                s += s100 + s010 + s001
            case 4:
                s += s101 + s000 + s101
            case 5:
                s += s101 + s010 + s101
            case 6:
                s += s111 + s000 + s111

        s += ("+-----+\n")
        return s


class RolaDados:
    def __init__(self, n, seed):
        self.dados = []

        r = Random(seed)
        r.seed(seed)
        for i in range(n):
            if(seed == 0):
                self.dados.append(Dado())
            else:
                self.dados.append(Dado(6, r.randint(1,10000)))
    
    def rolar(self, quais=[]):
        i = 0
        r = []
        for b in quais:
            if(i >= len(self.dados)):
                break
            if(b):
                self.dados[i].rolar()
            r.append(self.dados[i].getLado())
            i += 1
        
        return r
    
    def rolar_str(self, s):
        b = [False] * len(self.dados)
        if s.strip():  
            for num in s.split():
                try:
                    i = int(num) - 1  
                    if 0 <= i < len(self.dados):
                        b[i] = True
                except: ValueError
        return self.rolar(b)
    
    def mostrarDados(self):
        s = ""
        for i in range(5):
            base = i*8
            for d in self.dados:
                p = d.toString()
                s += p[base:base+7]
                s += "    "
            
            s += "\n"
        
        return s
    
    def __str__(self):
        s = ""
        for i in range(5):  
            base = i * 8    
            for d in self.dados:
                p = str(d)  
                s += p[base:base+7]
                s += "    "  
            s += "\n" 
        return s



class Placar:
    
    def __init__(self):
        self.POSICOES = 10
        self.placar = [0] * self.POSICOES  # Inicializa com zeros
        self.taken = [False] * self.POSICOES

    def add(self, posicao, dados):

        if (self.taken[posicao-1]):
            raise ValueError("Posição ocupada")
        k = 0
        match posicao:
            case 1: 
                k = self.conta(1, dados)
            case 2:
                k = 2 * self.conta(2, dados)
            case 3:
                k = 3 * self.conta(3, dados)
            case 4:
                k = 4 * self.conta(4, dados)
            case 5:
                k = 5 * self.conta(5, dados)
            case 6:
                k = 6 * self.conta(6, dados)
            case 7: #full hand
                if self.checkFull(dados):
                    k = 15
            case 8: # sequencia
                if self.checkSeqMaior(dados):
                    k = 20
            case 9: # quadra
                if self.checkQuadra(dados):
                    k = 30
            case 10: # full hand
                if self.checkQuina(dados):
                    k = 40
            case _: 
                raise ValueError("Valor da posição ilegal")
            
        self.placar[posicao-1] = k
        self.taken[posicao-1] = True

    def getScore(self):
        t = 0
        for i in range(self.POSICOES):
            if self.taken[i]:
                t += self.placar[i]

        return t

        
    def conta(self, n, vet):
        cont = 0
        for i in vet:
            if i == n:
                cont += 1

        return cont
    
    def checkFull(self, dados):
        v = sorted(dados)
        return (v[0] == v[1] and v[1] == v[2] and v[3] == v[4]) or ( v[0] == v[1] and v[2] == v[3] and v[3] == v[4])

    def checkQuadra(self, dados):
        v = sorted(dados)
        return (v[0] == v[1] and v[1] == v[2] and v[2] == v[3]) or ( v[1] == v[2] and v[2] == v[3] and v[3] == v[4])

    def checkQuina(self, dados):
        v = dados[:]
        return ( v[0] == v[1] and v[1] == v[2] and v[2] == v[3] and v[3] == v[4])

    def checkSeqMaior(self, dados):
        v = sorted(dados)
        return ( v[0] == v[1]-1 and v[1] == v[2]-1 and v[2] == v[3]-1 and v[3] == v[4]-1)
    
    def __str__(self):
        s = ""
        for i in range(3):
            num = f" {self.placar[i]:<3}" if self.taken[i] else f"({i+1}) "
            s += num + "   |   "

            num =  f" {self.placar[i+6]:<3}" if self.taken[i+6] else f"({i+7}) "
            s += num + "   |  "

            num =  f" {self.placar[i+3]:<3}" if self.taken[i+3] else f"({i+4}) "
            s += num + "\n-------|----------|-------\n"

        num =  f" {self.placar[9]:<3}" if self.taken[9] else f"(10)"
        s += "       |   " + num + "   |"
        s += "\n       +----------+\n"
        return s

class EntradaTeclado:
    
    def leString():
        return input()

    def leInt():
        return int(EntradaTeclado.leString())

    def leDouble():
        return float(EntradaTeclado.leString())


if __name__ == "__main__":
    main() 