	.data
	.align 0
str_entrada:	.asciz "Digite um número"
str_saida: 	.asciz "Resultado:"

	.text
	.align 2
	.globl main
	
main:
li a7, 4
la a0, str_entrada
ecall #printa str entrada

li a7, 1
ecall #recebe a  entrada

mv s0, a0 #salva em s0 a entrada

jal fatorial_rec

mv a0, a1
li a7, 4
ecall
li a7, 1
ecall
li a7, 10
ecall




#entrada em a0
#saida em a1
#s1 recbe os valores intermediarios
fatorial_rec:
#empilhar
sw ra, 0(sp) #addres intermediario
sw a0, 4(sp) #valor intermediario
addi sp, -8 #corrige o ponteiro sp

#condicao de parada
beq a0, zero, return_1


addi, a0, a0, -1 #(a0 = a0-1)
#a1 recebe (a0-1)#a0
jal fatorial 

add a0, a0, 1 #o ultimo a0 sera 0, portanto é necessario corrigir o valor
mul a1, a1, a0
jr ret_fat
   
return_1:
li a1, 1

ret_fat: #desempilha
lw ra, 0(sp)
lw a0, 4(sp)
addi sp, sp, 8

jr ra 

