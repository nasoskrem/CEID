      .data
num1_0: .word 0xFFFFFFFF
num1_1: .word 0x00000000
num2_0: .word 0x00000000
num2_1: .word 0xFFFFFFFF
result: .space 8

    .text            # Program code goes in this section
    .globl main
main:                # Execution starts here           
    
    la    x18, num1_0
    la    x19, num1_1
    
    lw    x18, 0(x18)
    lw    x19, 0(x19) # A = 0x0000000011111111
    
    la    x20, num2_0
    la    x21, num2_1
    
    lw    x20, 0(x20)
    lw    x21, 0(x21) # B = 0x1111111100000000
    
    add   x22, x18, x20 # Kato 32
    
    srli  x18, x18, 31  
    srli  x20, x20, 31  
    srli  x5, x22, 31  	
    
    xori  x5, x5, 1  

    and   x28, x18, x20 
    xor   x29, x18, x20 
    
    and   x30, x29, x5
    or    x31, x30, x28 # Carry kato 32 prosthesi
    
    add   x6, x19, x21
    add   x6, x6, x31 # Pano 32
    
    la    x7, result
    sw    x22, 0(x7)
    sw    x6, 4(x7)
    
    
    li    a7, 10     # Done, terminate program
    ecall            # au revoir...
    