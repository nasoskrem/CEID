# lab5-2.s

#---------------------- data segment ---------------------#
    .data
msg1:       .asciz "Enter the number of integers to allocate: "
msg2:       .asciz "Enter the integers:\n"
msg3:       .asciz "The maximum value is: "
max_val:    .word 0  # Memory to store the maximum value


#---------------------- text segment ---------------------#
    .text
    .globl main
main:
    # Prompt for the number of integers
    la    a0, msg1                  # Load address of msg1
    li    a7, 4                     # Print string syscall
    ecall

    # Read number of integers
    li    a7, 5                     # Read integer syscall
    ecall
    add   t0, x0, a0                # t0 = number of integers
    
    li    t1, 4
    mul   t1, t0, t1
    
    addi  a0, t1, 0
    li    a7, 9
    ecall
    
    addi  s0, a0, 0

    # Prompt for integer input
    la    a0, msg2                  # Load address of msg2
    li    a7, 4                     # Print string syscall
    ecall

    # Input integers and store them in allocated memory
    add   t2, x0, s0                # t2 = pointer to allocated memory
    add   t3, x0, t0                # t3 = number of integers

input_loop:
    beq   t3, x0, find_max          # If counter is 0, go to find_max

    li    a7, 5                     # Read integer syscall
    ecall
    sw    a0, 0(t2)                 # Store input integer in memory
    addi  t2, t2, 4                 # Move to the next memory location
    addi  t3, t3, -1                # Decrease counter
    jal   x0, input_loop            # Repeat

find_max:
    add   t2, x0, s0                # t2 = pointer to start of memory
    lw    t4, 0(t2)                 # Load the first element
    add   t3, x0, t0                # t3 = number of elements

max_loop:
    beq   t3, x0, print_max         # If counter is 0, go to print_max
    lw    t5, 0(t2)                 # Load current element
    blt   t4, t5, update_max        # If current element > t4, update max
    jal   x0, next

update_max:
    add   t4, x0, t5                # Update max value

next:
    addi  t2, t2, 4                 # Move to next element
    addi  t3, t3, -1                # Decrease counter
    jal   x0, max_loop              # Repeat

print_max:
    la    a0, max_val               # Load address of max_val
    sw    t4, 0(a0)                 # Store the max value

    # Print the maximum value
    la    a0, msg3                  # Load address of msg3
    li    a7, 4                     # Print string syscall
    ecall

    lw    a0, max_val               # Load the max value
    li    a7, 1                     # Print integer syscall
    ecall 

    li    a7, 10                    # Done, terminate program.
    ecall                           # au revoir...

#----------------------- End of File ---------------------#
