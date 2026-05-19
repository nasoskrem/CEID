    .data

    .text            # Program code goes in this section
    .globl main
main:                # Execution starts here

    srli   t2, t1, 1
    xor    t2, t1, t2
    	
    li    a7, 10     # Done, terminate program
    ecall            # au revoir...
    