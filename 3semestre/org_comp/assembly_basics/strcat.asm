	.data
	.align 0
str_num: 	.asciz "digite quantos caracteres: "
str_entrada:.asciz "digite uma string: "
str_saida:	.asciz "resultado: \n"
str_nl:	.asciz "\n"

	.align 2
p_str1:	.word
p_str2:	.word
p_saida:	.word

	.text
	.align 2
	.globl main

main:

la a1, p_str1
jal le_e_aloca
mv s0, a0

la a1, p_str2
jal le_e_aloca
mv s1, a0

li a7, 9 #sbr string a ser copiada
add a0, s0, s1 #tamanho da nova string
addi a0, a0, 1
ecall

la t0, p_saida
sw a0, 0(t0)

la t0, p_str1
lw a1, 0(t0) #endereco str1
la t0, p_saida
lw a0, 0(t0) #endereco str_saida
jal str_cp

la t0, p_str2
lw a1, 0(t0) #endereco str2
la t0, p_saida
lw a0, 0(t0)
add a0, a0, s0  #endereco str_saida ajustado para o primeiro byte livre
jal str_cp

finaliza:
li a7, 4
la a0, str_saida
ecall #printa str de saida

la t0, p_saida
lw a0, 0(t0) #endereco str de saida
li a7, 4
ecall #printa resultado

li a7, 10
ecall #finaliza programa


#a0 endereco destino
#a1 endereco fonte
#retorno: a0
str_cp:

loop_cp:

lb t0, 0(a1)
sb t0, 0(a0)
addi a0, a0, 1
addi a1, a1, 1

bne t0, zero, loop_cp

acaba:
jr ra


#a1 endereco ponteiro
#retorna em a0 o tamanho da string
le_e_aloca:
mv t0, a1

li a7, 4
la a0, str_num
ecall #rpinta str_num
	
li a7, 5
ecall #le a quantidade de caracteres
addi a0, a0, 1 #espacao pro \0
mv t1, a0


li a7, 9 #sbrk
ecall 

sw a0, 0(t0) #guarda ponteiro

li a7, 4
la a0, str_entrada
ecall #printa str_entrada

li a7, 8 #le string
mv a1, t1 #caracteres a serem lidos
lw a0, 0(t0) #endereco do espaco alocado
ecall


li a7, 4
la a0, str_nl
ecall

# Debug: imprime a string lida
    li a7, 4
    lw a0, 0(t0)
    ecall
   
mv a0, t1

jr ra
