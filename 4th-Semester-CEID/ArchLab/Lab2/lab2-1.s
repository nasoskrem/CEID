    .data
msg: .asciz "You entered: "



    .text            # Program code goes in this section
    .globl main
main:                # Execution starts here

    li   a7, 5
    ecall
    add  t0, x0, a0
    
    la   a0, msg
    li   a7, 4
    ecall
    
    addi  a0, t0, 0
    li   a7, 1
    ecall
    
    li    a7, 10     # Done, terminate program
    ecall            # au revoir...

#----------------------- End of File ---------------------#
