# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
#********************************************************************************#
# Multiplication using repeated addition
# a*b is returned in r5

# x1:a, x2:b, x3: is_neg
# x5: ans
_START_:
        addi x1, x0, 10
        addi x2, x0, -10
        addi x3, x0, 0
        addi x5, x0, 0
        blt  x0, x1, LOOP
        addi x3, x0, 1
        addi x4, x0, -1
        xor  x1, x1, x4
        addi x1, x1, 1
LOOP:
        beq x0, x1, DONE
        add x5, x5, x2
        addi x1, x1, -1
        jal x0, LOOP
DONE: 
        beq x0, x3, RET
        addi x4, x0, -1
        xor  x5, x5, x4
        addi x5, x5, 1
RET: 
        sw x5 84(x0)  
        jal x0, RET