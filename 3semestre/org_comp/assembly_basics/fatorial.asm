    .data
    #dados do programa
#fatorial: .word #resultado do cálculo 
#fat_aux: .half #numero auxiliar para o calculo do fatorial

    .text
    #código do programa
    .align 2
    .globl main

main:
    li a7, 5
    ecall #recebe entrada

    li s0, 1 #iniciliza o resultado do fatorial como 1
    add s1, a0, zero #carrega o valor auxiliar

calc_fat:
    mul s0, s0, s1 #calcula o valor do fatorial até o momento
    li t0, 1 #guarda o valor 1 
    sub s1, s1, t0  #decresce o valor do auxiliar

    bgt s1, t0, calc_fat #mantém o loop caso o auxiliar seja > 1
    

    add a0, s0, zero #carrega o resultado no registrador de saída
    li a7, 1 #intrucao de printar numero
    ecall #printa o numero

    li a7, 10
    ecall #finaliza o programa


