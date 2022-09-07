#
# @author:Don Dennis
# push_pop_halt_test.rvi
#
# Testing functions PUSH, POP
# and HALT. There are used as
# pseudo instructions in other programs

## Convention
# x31: Return Address
# x30: Stack Pointer
# x29: Return value 
# x1:arg1
# x2:arg2
# x3:temp

_START:
    addi x3,x0,2047
    addi x30,x0,20
    jal  x31,PUSH
    addi x3, x0, 1
    jal x31,POP
HALT:
    sw x31 80(x0)
    sw x30 84(x0)
    jal x31, HALT

# Increments stack pointer and
# pushes the value in x3 to stack
PUSH:
    addi x30,x30,4
    sw   x3, 0(x30)
    jalr x0,x31,0
# Pops the value from stack to x3
# and decrements stack pointer
POP:
    lw x3, 0(x30)
    addi x30,x30,-4
    sw x31 80(x0)
    jalr x0,x31,0    

SWAP:
    add x3,x0,x1
    add x1,x0,x2
    add x2,x0,x3
    jalr x0,x31,0