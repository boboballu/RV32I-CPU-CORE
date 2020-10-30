lui x1 16		
addi x1 x1 -4	#x1 = 65532

addi x10 x0 10
call sw
addi x10 x10 1
sw:
sw x10 0(x1)
