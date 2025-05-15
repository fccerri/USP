    .data   
    .align 0
str_src: .asciz "Oi mãe, to na usp"
str_dst: .space 24 #reserva 24 bytes na parte de dados estáticos

    .text
    .align 2
    .globl main 

main: 
    la s0, str_src
    la s1, str_dst

loop: 
    lb t0, 0(s0)
    sb t0, 0(s1)
    addi s0, s0, 1
    addi s1, s1, 1
    bne t0, zero, loop
    li a7, 4
    la a0, str_dst
    ecall

    li a7, 10
    ecall