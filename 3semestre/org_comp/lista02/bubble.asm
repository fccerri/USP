	.data
    #dados do codigo
    .align 2
vet: .word  7, 5, 2, 1, 1, 3, 4

    .text 
    .globl main 

main:
    la s0, vet #carrega os valores nos registradores
    li s1, 0 #i
    li s3, 7 #tam
    

loop_externo:
    bge s1, s3, fim_bubble #condicao de parada loop interno
    
    li s2, 0 # s2 = j = 0

loop_interno:
    sub t0, s3, s1 #t0 = max
    addi t0, t0, -1 # ajuste para acessar o indice correto
    bge s2, t0, proximo_loop_externo #condicao de parada loop interno

    slli t2, s2, 2 #calcula o endereco do elemento j em relacao a base
    add t2, t2, s0 #acha j na memoria 
    lw t0, 0(t2) #carrega vet[j] 

    lw t1, 4(t2) #carrega vet[j+1] 

    addi s2, s2, 1 #incrementa j

    bgt t0, t1, troca 
    
    j loop_interno

troca: 
    sw t1, 0(t2) #vet[j] recebe vet[j+1]
    sw t0, 4(t2) #vet[j+1] recebe vet[j]
    j loop_interno


proximo_loop_externo:
     addi s1, s1, 1 #ajuste do i
     j loop_externo
     
fim_bubble:

    li s1, 0 #i
    li a7, 1

imprime: 
    bge s1, s3, encerra

    slli t0, s1, 2 #endereco de vet[i] relativo a base 
    add t0, t0, s0 #endereco de vet[i] na memoria
    lw a0, 0(t0)
    ecall

    addi s1, s1, 1
    j imprime

encerra:     
    li a7, 10
    ecall

