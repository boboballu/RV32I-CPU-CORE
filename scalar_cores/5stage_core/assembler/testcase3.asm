# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
#********************************************************************************#
#testcase3.asm tests branch instn, jump, load, store, alu instructions

addi $2 $0 5        	# initialize $2 = 5
addi $3 $0 10       	# initialize $3 = 10
j >jump_tag1

add $3 $2 $3			# $3 = $2 + $3 // 15
sw $3 10 $(2)			# store $3 to 15

sub $3 $2 $3 <jump_tag1	# $3 = $2 - $3 // -5
addi $4 $0 -5			# initialize $4 = -5
#sw $4 10 $(0)           # store $4 to 10 // -5
beq $3 $4 >branch		# branch if $3 == $4 // -5 == -5 hence taken (branch stalls)
sw $4 10 $(0)           # store $4 to 10 // -5 (just to test whether the branch is taken)
sub $4 $4 $3			# not taken: $4 = $4 - $3 // 0
slt $5 $0 $4 <branch	# taken target - branch:  $5 = 1 if $4 < $0 else 0
sw $0 11 $(0)           # store $0 to 11 // just checking
sw $4 12 $(0)           # store $4 to 12 // just checking
sw $5 10 $(2)			# store $5 to 15  // 1
hlt