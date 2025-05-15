	.data
	.align 0
str_entrada1:	.asciz "Insira o numero de caracteres da string: "
str_entrada2:	.asciz "Insira a string: "
str_saida:	.asciz "a string invertida eh:\n"
str_nl:	.asciz "\n"

	.align 2
p_str_cp: 	.word 
p_str_saida:	.word

	.text
	.align 2
	.globl main

main:
li a7, 4 #printa str entrada 1
la a0, str_entrada1
ecall

li a7, 5
ecall #recebe o numero de caracteres

mv s0, a0 #guarda o numero de caracteres
addi a0, a0, 1 #espaco pro \0
li a7, 9 #sbrk (a0 ja tem espaco a ser armazenado)
ecall

la t0, p_str_cp
sw a0, 0(t0) #guarda o ponteiro para a string a ser copiada

li a7, 4 #printa str entrada 2
la a0, str_entrada2
ecall

la t0, p_str_cp #endereco que sera armazenada a string
lw a0, 0(t0)
mv a1, s0 #caracteres maximos
addi a1, a1, 1 #espaco para o /0
li a7, 8
ecall #le string

li a7, 4
ecall 

mv a0, s0
addi a0, a0, 1 #espaco pro /0
li a7, 9 #sbrk string de saida
ecall

la t0, p_str_saida
sw a0, 0(t0) #guarda o ponteiro para a string de saida

li a7, 4
la a0, str_nl
ecall #printa nl 

mv t0, s0 #contador
la t1, p_str_cp #ponteiro string original
lw t1, 0(t1)
add t1, t1, s0 #aponta para o final da string
addi t1, t1, -1 #corrige pulando o /0
la t2, p_str_saida #ponteiro string saida
lw t2, 0(t2)

loop_de_invercao:
beq t0, zero, finaliza

lb t3, 0(t1) #byte a ser escrito
addi t1, t1, -1 #percorre do ultimo ao primeiro caracter da string

sb t3, 0(t2) #escreve o byte
addi t2, t2, 1 #percorre do primeiro ao ultimo caracter da string

addi t0, t0, -1 #decrmeneta contador

j loop_de_invercao

finaliza:
li a7, 4
la a0, str_saida
ecall 

#coloca /0 no final da string
sb zero, 0(t2)

li a7, 4
la t0, p_str_saida
lw a0, 0(t0) #passa o ponteiro para a string de saida
ecall #imprime result

li a7, 10
ecall #finaliza








