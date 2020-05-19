# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
#********************************************************************************#
#testcase2.asm test unconditional jump, load, store, alu instructions

addi $2 $0 5        	# initialize $2 = 5
addi $3 $0 10       	# initialize $3 = 10
j >jump_tag1

add $3 $2 $3			# $3 = $2 + $3 // 15
sw $3 10 $(2)			# store $3 to 15

sub $3 $2 $3 <jump_tag1	# $3 = $2 - $3 // -5
sw $3 10 $(2)			# store $3 to 15