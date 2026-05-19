    .data 
addition: .asciz "Αποτέλεσμα πρόσθεσης: "
substraction: .asciz "\nΑποτέλεσμα αφαίρεσης: "


    .text            # Program code goes in this section
    .globl main
main:                # Execution starts here
    li   a7, 5
    ecall
    add  t0, x0, a0
    
    li   a7, 5
    ecall
    add  t1, x0, a0
    
    add  t2, t0, t1
    sub  t3, t0, t1
    
    la   a0, addition
    li   a7, 4
    ecall
    
    addi  a0, t2, 0
    li   a7, 1
    ecall
    
    la   a0, substraction
    li   a7, 4
    ecall
    
    addi  a0, t3, 0
    li   a7, 1
    ecall
    
li    a7, 10     # Done, terminate program
    ecall            # au revoir...

#----------------------- End of File ---------------------#
