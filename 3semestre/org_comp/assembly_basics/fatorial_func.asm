    .data
    .align 2
fat_res: .word 
    .text
    .align 2
    .globl main


main:
li a7, 5 #leitura da variavel
ecall 

add a1, a0, zero  #passa o parametro para funcao 
jal s7, fat_calc #chamada da funcao

la t0, fat_res  
sw a0, 0(t0) #guarda o resultado na memoria

li a7, 1 #printa
ecall

li a7, 10
ecall #finaliza o programa

	
#a1 - fatorial que queremos calcular 
#a0 - retorno da funcao
fat_calc:
mv t0, a1 #variavel contadora e auxiliar para o calculo 
li a0, 1 #resultado 

loop_calculo:
ble t0, zero, finaliza 

mul a0, a0, t0 #resultado parcial 
addi t0, t0, -1 #decrescimo do contador/aux
j loop_calculo

finaliza:
jr s7 #retorno da funcao 

