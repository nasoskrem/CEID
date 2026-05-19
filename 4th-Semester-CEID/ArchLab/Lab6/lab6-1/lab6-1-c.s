
    .data   # Data declarations go in this section
msg1:       .asciz "Exception with cause "
msg2:       .asciz " due to "
msg3:       .asciz " occured at address "

ermsg1:     .asciz "Load access fault"        # (ucause code: 5)
ermsg2:     .asciz "Load address misaligned"  # (ucause code: 4)
ermsg3:     .asciz "Illegal instruction"      # (ucause code: 2)


#---------------------- text segment ---------------------#
    .text
    .globl main
main:
    csrsi  ustatus, 1        # Set interrupt enable (instr: csrrsi x0, ustatus, 1)
    la     t0, exception_handler  # t0 <-- trap handler address
    csrw   t0, utvec         # Set utvec with trap handler address (instr: csrrw x0, utvec, t0)

    li     x9, 0x100       
    lw     x5, 0(x9)         # Exception due to Load access fault (ucause code: 5)
    
    li     a7, 10            # Done, terminate program (exit 0)
    ecall                    # au revoir...

exception_handler:
    la     a0, msg1
    li     a7, 4
    ecall
    
    csrr   t1, ucause
    add    a0, t1, x0
    li     a7, 1
    ecall
    
    la     a0, msg2
    li     a7, 4
    ecall
    
    li     t2, 5
    beq    t1, t2, Ermsg1
    
    li     t2, 4
    beq    t1, t2, Ermsg2

    li     t2, 2
    beq    t1, t2, Ermsg3 
    j      Msg3
    
Ermsg1:
    la     a0, ermsg1
    j      print

Ermsg2:
    la     a0, ermsg2
    j      print
    
Ermsg3:
    la     a0, ermsg3
    
print:
    li     a7, 4
    ecall
    
Msg3:
    la     a0, msg3
    li     a7, 4
    ecall
    
    csrr   a0, uepc
    li     a7, 1
    ecall

    csrc   x0, ucause         # Clear ucause register (instr: csrrw a0, ucause, x0)  
    la     t0, end
    csrw   t0, uepc           # Move epc to success and return (instr: csrrw x0, uepc, t0)
    uret

end:
    li     a0, -1
    li     a7, 93             # Done, terminate program with code
    ecall                     # exit -1 (with errors)