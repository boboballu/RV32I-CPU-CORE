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
    j end               # loop when finished if there is no environment to return to.
