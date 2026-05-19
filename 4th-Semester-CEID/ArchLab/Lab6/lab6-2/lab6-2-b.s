# lab6-2-b.s

#---------------------- data segment ---------------------#
    .data   
buffer:  .word 0x12345678, 0x88776655   # Two words in memory (aligned)


#---------------------- text segment ---------------------#
    .text                    # Program code goes in this section
    .globl main
main:
    csrsi  ustatus, 1        # Set interrupt enable (instr: csrrsi x0, ustatus, 1)
    la     x18, exception_handler  # x18 <-- trap handler address
    csrw   x18, utvec        # Set utvec with trap handler address (instr: csrrw x0, utvec, x18)

    la     x10, buffer  
    addi   x10, x10, 3       # Hopefully we'd have x10 <- 0x77665512 (recall: little endian)
    lw     x5, 0(x10)        # Exception due to Load address misaligned (ucause code: 4)
    
    li     a7, 10            # Done, terminate program (exit 0)
    ecall                    # au revoir...

exception_handler:
    # --- 1. Φόρτωση των 4 ξεχωριστών bytes ---
    lbu    x6, 0(x10)      # LSB (byte 0): Unsigned για αποφυγή επέκτασης προσήμου
    lbu    x7, 1(x10)      # Byte 1: Unsigned
    lbu    x8, 2(x10)      # Byte 2: Unsigned
    lb     x9, 3(x10)      # MSB (byte 3): Εδώ μπορούμε να βάλουμε lb (Signed) 
                           # για να διατηρηθεί το πρόσημο ολόκληρης της 32-bit λέξης.

    # --- 2. Ολίσθηση (Shift) στις σωστές θέσεις ---
    # Το x6 είναι ήδη στη σωστή θέση (bits 0-7)
    slli   x7, x7, 8       # Ολίσθηση 8 bits αριστερά (bits 8-15)
    slli   x8, x8, 16      # Ολίσθηση 16 bits αριστερά (bits 16-23)
    slli   x9, x9, 24      # Ολίσθηση 24 bits αριστερά (bits 24-31)

    # --- 3. Σύνθεση της λέξης στον καταχωρητή στόχο (x5) ---
    or     x5, x6, x7      # Ένωση των δύο πρώτων bytes
    or     x5, x5, x8      # Προσθήκη του τρίτου byte
    or     x5, x5, x9      # Προσθήκη του MSB. Ο x5 έχει πλέον τη σωστή τιμή!

    # --- 4. Ενημέρωση του uepc για επιστροφή στην επόμενη εντολή ---
    csrc   x0, ucause         # Clear ucause register (instr: csrrw a0, ucause, x0)  
    la     t0, end
    csrw   t0, uepc           # Move epc to success and return (instr: csrrw x0, uepc, t0)
    uret

end:
    li     a0, -1
    li     a7, 93             # Done, terminate program with code
    ecall                     # exit -1 (with errors)




#----------------------- End of File ---------------------#
