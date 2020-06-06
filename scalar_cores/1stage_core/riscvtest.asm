# mipstest.asm
# David_Harris@hmc.edu, Sarah_Harris@hmc.edu 31 March 2012
#
# Test the MIPS processor.
# add, sub, and, or, slt, addi, lw, sw, beq, j
# If successful, it should write the value 7 to address 84
#       Assembly                    Description             Address                     Machine
main:   addi x2, x0, 5              # initialize x2 = 5       0           		20020005
        addi x3, x0, 12             # initialize x3 = 12      4          		2003000c
        addi x7, x3, −9             # initialize x7 = 3       8           		2067fff7
        or x4, x7, x2               # x4 = (3 OR 5) = 7       c           		00e22025
        and x5, x3, x4              # x5 = (12 AND 7) = 4     10        		00642824
        add x5, x5, x4              # x5 = 4 + 7 = 11         14            	        00a42820
        beq x5, x7, end             # shouldn't be taken      18         		10a7000a
        slt x4, x3, x4              # x4 = 12 < 7 = 0         1c            	        0064202a
        beq x4, x0, around          # should be taken         20            	        10800001
        addi x5, x0, 0              # shouldn’t happen        24           		20050000
around: slt x4, x7, x2              # x4 = 3 < 5 = 1          28             	        00e2202a
        add x7, x4, x5              # x7 = 1 + 11 = 12        2c           		00853820
        sub x7, x7, x2              # x7 = 12 − 5 = 7         30            	        00e23822
        sw x7, 68(x3)               # [80] = 7                34                        ac670044
        lw x2, 80(x0)               # x2 = [80] = 7           38              	        8c020050
        j end                       # should be taken         3c            	        08000011
        addi x2, x0, 1              # shouldn't happen        40           		20020001
end:    sw x2, 84(x0)               # write mem[84] = 7       44          		ac020054