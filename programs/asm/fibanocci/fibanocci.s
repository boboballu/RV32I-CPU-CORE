# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
#********************************************************************************#
# Find the Nth fibonacci number.
# x5 holds N and ans returned in x3

li x25, 4194308 # console addr
li x26, 4194312 # stop addr


addi x5,x0, 7	# Replace with N
addi x1,x0,1 	#a1
addi x2,x0,0 	#a0
addi x3,x0,0 	#ans
addi x4,x0,1 	#i
FOR:
	add x3, x1, x2
	add x2, x0, x1
	add x1, x0, x3
	addi x4, x4, 1
	blt x4, x5, FOR

PRINT:
	sw x3 0(x25)
	j HALT

HALT:	
	addi x1,x0,1
	sw x1, 0(x26)
	j HALT