      .data
initx: .word 25
inity: .word 13
uninitz: .space 4

    .text            # Program code goes in this section
    .globl main
main:                # Execution starts here           
    
    la    a2, initx
    lw    a2, 0(a2)
    
    la    a3, inity
    lw    a3, 0(a3)
    
    jal   ra, sumIt
    
    la    t0, uninitz
    sw    a0, 0(t0)
    
    li    a7, 10     # Done, terminate program
    ecall            # au revoir...
    
sumIt: # epistrefei a0
    addi  sp, sp, -8
    sw    a2, 0(sp) # initx
    sw    ra, 4(sp)
    
    jal   ra, sumItAgain
    
    lw    a2, 0(sp)
    lw    ra, 4(sp)
    addi  sp, sp, 8
 
    add   a0, a1, a2 # initx + sumItAgain(inity)
    
    jalr  x0, 0(ra)

sumItAgain: # epistrefei a1
    addi  a1, a3, 10 # inity + 10
    jalr  x0, 0(ra)