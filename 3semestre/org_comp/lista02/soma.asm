    .data
    .align 2
p: .word # ponteiro

    .text
    .align 2
    .globl main 

main:

entrada:
    li a7, 5
    ecall
    mv s0, a0 #tam 

    slli a0, s0, 2 #calcula a quantidade de bytes
    li a7, 9 #sbrk
    ecall

    mv s1, a0 #base do vetor em s1
    sw s1, p #guarda o endereco da memoria alocada no ponteiro 
    li t0, 0 #contador
    
leitura_vet:
    bge t0, s0, fim_leitura
    li a7, 5
    ecall

    slli t1, t0, 2 #ajuste do ponteiro em relacao a base
    add t1, t1, s1 #posicao na memoria
    sw a0, 0(t1) #armazena um elemento do vetor

    addi t0, t0, 1 #incrementa contador
    j leitura_vet

fim_leitura:

    li t0, 0 #contador
    li s2, 0 #acumulador

soma:
    bge t0, s0, imprime

    slli t1, t0, 2 #ajuste do ponteiro em relacao a base
    add t1, t1, s1 #posicao na memoria
    lw t2, 0(t1)
    add s2, s2, t2 #soma os valores

    addi t0, t0, 1 #incrementa contador
    j soma

imprime:
    mv a0, s2
    li a7, 1
    ecall

finaliza:
    li a7, 10
    ecall    
