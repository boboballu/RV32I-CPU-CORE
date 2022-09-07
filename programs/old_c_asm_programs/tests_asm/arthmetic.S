lui x14 1
addi x14 x14 -1    #x14 = 4095

lui x1 16        
addi x1 x1 -4    #x1 = 65532

sw x14 0(x1) # 4095

addi x2 x1 0
slt x3 x2 x1
sw x3 0(x1)        #0
addi x2 x2 1
slt x3 x2 x1
sw x3 0(x1)        #0
addi x2 x2 -2
slt x3 x2 x1
sw x3 0(x1)        #1

addi x2 x0 -1
addi x3 x0 -2
slt x4 x3 x2
slti x5 x3 -1
sw x4 0(x1)   #1
sw x5 0(x1)   #1
sltu x4 x3 x2
sltiu x5 x3 -1
sw x4 0(x1)   #1
sw x5 0(x1)   #1
sltu x4 x2 x3
sltiu x5 x2 -2
sw x4 0(x1)   #0
sw x5 0(x1)   #0




