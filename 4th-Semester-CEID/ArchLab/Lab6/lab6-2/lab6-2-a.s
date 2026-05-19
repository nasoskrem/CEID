# lab6-2-a.s

#---------------------- data segment ---------------------#
    .data   
buffer:  .word 0x12345678, 0x88776655   # Two words in memory (aligned)


#---------------------- text segment ---------------------#
    .text                    # Program code goes in this section
    .globl main
main:
    la     x10, buffer  
    addi   x10, x10, 3       # Hopefully we'd have x10 <- 0x77665512 (recall: little endian)
    lw     x5, 0(x10)        # Exception due to Load address misaligned (ucause code: 4)
    
    li     a7, 10            # Done, terminate program (exit 0)
    ecall                    # au revoir...


#----------------------- End of File ---------------------#
