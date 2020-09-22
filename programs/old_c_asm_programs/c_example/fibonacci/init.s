#Author: Tarun Govind Kesavamurthi
#School: North Carolina State University
#mail  : tkesava@ncsu.edu

# RISC-V baremetal init.s
# This code is executed first.

.section .text.init
# entry point of execution
entry:

    la    sp, __sp-32   # set up the stack pointer, using a constant defined in the linker script.

    call  main          # call the main function

end:
    j end               # loop when finished if there is no environment to return to.
