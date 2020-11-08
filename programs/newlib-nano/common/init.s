# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu

# RISC-V baremetal init.s
# This code is executed first.

# RISC-V assembly programmer's Manual (Assembler Prefix, ABI etc)
# https://github.com/riscv/riscv-asm-manual/blob/master/riscv-asm.md

# section name like .text_init screws up. Have no idea why
.section .init
# entry point of execution
entry:
    la    sp, __sp      # set up the stack pointer, using a constant defined in the linker script.
    call  textinit      # call the main function
end:
    addi t1, t1, 1
    la t2, __stop_addr  # 65548
    sw t1, 0(t2)
loop:
    j loop              # loop when finished if there is no environment to return to.
