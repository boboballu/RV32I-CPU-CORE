# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
#********************************************************************************#
#testcase1.asm checks loads stores and all alu operations (branch and jump is not tested)
#
addi $2 $0 5        #initialize $2 = 5
addi $3 $0 10       #initialize $3 = 10
add $4 $3 $2        # $4 = $3 + $2 // 15
sub $5 $3 $2        # $5 = $3 - $2 // 5
sub $6 $2 $3        # $6 = $2 - $3 // -5
and $7 $3 $2        # $7 = $3 & $2 // 0
nop                 # no operation
or $8 $3 $2         # $8 = $3 | $2 // 14
slt $9 $2 $3        # $9 = $2 < $3 // 1
slt $10 $3 $2       # $10 = $3 < $2 // 0

sw $2 80 ($0)       # store $2 to mem[80]
sw $3 84 ($0)       # store $3 to mem[84]
sw $4 88 ($0)       # store $4 to mem[88]
sw $5 92 ($0)       # store $5 to mem[92]
sw $6 96 ($0)       # store $6 to mem[96]
sw $7 100 ($0)      # store $7 to mem[100]
sw $8 104 ($0)      # store $8 to mem[104]
sw $9 108 ($0)      # store $9 to mem[108]
sw $10 112 ($0)     # store $10 to mem[112]

lw $11 80 ($0)      # load $11 = mem[80] // 5
lw $12 108 ($0)     # load $12 = mem[108] // 1
# nop
# nop                 # a bug found // lw followed by alu op takes 2 cycle stall for some reason
add $13 $11 $12     # $13 = $11 + $12 // 6
sw $13 116 ($0)     # store $13 to mem[116]