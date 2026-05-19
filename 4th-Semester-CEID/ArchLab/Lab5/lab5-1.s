    .data
myVector: .word 14, 36, 88, 76, 5
vecSum: .word 0

    .text
    .globl main
main:
     la a0, myVector
     la a3, vecSum
     addi t0, x0, 5
for: beq t1, t0, exit
     lw a1, 0(a0)
     add a2, a2, a1
     sw a2, 0(a3)
     addi a0, a0, 4
     addi t1, t1, 1
     jal x0, for
     
exit:
    li a7, 10
    ecall
     
     