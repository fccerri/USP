    .data
    .align 0
str_src: .asciz "Me copia aqui"
    .align 2
p_str: .word #ponteiro para a string que será alocada

    .text
    .align 2
    .globl main

main:

li t0, 0 #contador
la s0, str_src #valor base da string

contagem:
mv t1, s0 #carrega valor base para outro registrador
add t1, t1, t0 #corrige o endereco com base no contador 
lb t2, 0(t1) #carrega em t2  o caractere da string
addi t0, t0, 1 #incrementa o contador

bne t2, zero, contagem #finaliza loop caso caracter seja "\0"

#alocacao
mv a0, t0 #guarda em a0 a qtd de bytes que sera alocados
li a7, 9 #sbrk
ecall

mv s1, a0 #endereco dos bytes alocados
la t0, p_str #endereco do ponteiro
sw s1, 0(t0) #guarda o endereco dos bytes alocados no ponteiro 

copia:
lb t0, 0(s0) #carrega em t0 o primeiro caracter da string de conteudo 
sb t0, 0(s1) #armazena o caractere na string destino 

addi s0, s0, 1 #atualiza os enderecos base
addi s1, s1, 1

bne t0, zero, copia #mantem loop enquanto caractere for diferente de 0

li a7, 4
la t0, p_str #endereco ponteiro string destino 
lw a0, 0(t0) #endereco da string destino  
ecall #printa

li a7, 10 #encerra o programa 
ecall  
