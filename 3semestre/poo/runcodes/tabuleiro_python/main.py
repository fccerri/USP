from tabuleiro import Tabuleiro 

str_numeros = input() #leitura da string de numeros
numeros = str_numeros.split() #separa string em um array de chars
str_op = input() #le a string de operacoes


tab = Tabuleiro(numeros)
tab.printa_tabuleiro()
tab.move_tabuleiro(str_op)

# print da linha final
print("Posicao final: ", end="")
if tab.valida_tabuleiro():
    print("True")
else:
    print("False")