    .data
space: .space 31


    .text            # Program code goes in this section
    .globl main
main:                # Execution starts here

    la    a0, space
    addi  a1, a1, 31
    li    a7, 8	
    ecall
    
    la    t0, space
    sb    x0, 5(t0)
    
    la    a0, space
    li    a7, 4
    ecall

    li    a7, 10     # Done, terminate program
    ecall            # au revoir...

#----------------------- End of File ---------------------#
