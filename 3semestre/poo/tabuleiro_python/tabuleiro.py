import math
import sys
#import random form Random
#rd.seed()

class Tabuleiro:
    def __init__(self, numeros):
        self.tamanho = int(math.sqrt(len(numeros)))
        self.tabela = [[0 for _ in range(self.tamanho)] for _ in range(self.tamanho)]
        self.l_vazia = -1
        self.c_vazia = -1
    
        for i in range(self.tamanho):
            for j in range(self.tamanho):
                self.tabela[i][j] = numeros[i*self.tamanho+j]
                if (numeros[i*self.tamanho+j] == '0'):
                    self.l_vazia = i 
                    self.c_vazia = j
    
    def printa_tabuleiro(self):
        for _ in range(self.tamanho):
            sys.stdout.write("+------")

        for i in range(self.tamanho):
            sys.stdout.write("+\n|")

            for j in range(self.tamanho):
                if int(self.tabela[i][j]) < 10:
                    sys.stdout.write(" ") #correção caso numero<10
                
                if (self.tabela[i][j] == '0'):
                    sys.stdout.write("     |")
                else:
                    sys.stdout.write("  {}  |".format(self.tabela[i][j]))
            
            sys.stdout.write("\n")
            for t in range(self.tamanho):  #printa em baixo dos numeros
                sys.stdout.write("+------")
            
        
        sys.stdout.write("+\n\n")
    
    def move_tabuleiro(self, str_op):
        l_update = 0
        c_update = 0
        for char in str_op:
            match char:
                case 'u':
                    l_update = 1
                    c_update = 0

                case 'd': 
                    l_update = -1
                    c_update = 0
                
                case 'l':
                    l_update = 0;
                    c_update = 1;
                
                case 'r': 
                    l_update = 0
                    c_update = -1
                    
                case _:
                    print("Operacao invalida")
                
            l_nova = self.l_vazia + l_update
            c_nova = self.c_vazia + c_update            
    
            if (0 <= l_nova < self.tamanho and 0 <= c_nova < self.tamanho):
                self.tabela[self.l_vazia][self.c_vazia] = self.tabela[l_nova][c_nova]
                self.tabela[l_nova][c_nova] = '0'

                self.c_vazia += c_update # att a posição vazia
                self.l_vazia += l_update

            self.printa_tabuleiro()

    def valida_tabuleiro(self):
        for i in range(self.tamanho):
            for j in range(self.tamanho):
                if (self.tabela[i][j] != str(i*self.tamanho+j)):
                    return False
                
        return True