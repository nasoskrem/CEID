      .data
num1: .word 0xF000BA30
num2: .word 0xB00B1E00

    .text            # Program code goes in this section
    .globl main
main:                # Execution starts here           

    la    x5, num1
    lw    x5, 0(x5)
    
    la    x6, num2
    lw    x6, 0(x6)
    
    add   x7, x5, x6
   
    srli  x5, x5, 31  
    srli  x6, x6, 31  
    srli  x7, x7, 31  
    
    xori  x7, x7, 1  

    and   x28, x5, x6 
    xor   x29, x5, x6 
    
    and   x30, x29, x7 
    or    x31, x30, x28
     
    li    a7, 10     # Done, terminate program
    ecall            # au revoir...
    