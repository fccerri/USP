    .data
     #dados do programa
hello_msg: .asciz "Hello World"

    .text
    #código do progrma
    .globl main

main: 

    la a0, hello_msg
    li a7, 4    
    ecall
    li a7 10
    ecall .