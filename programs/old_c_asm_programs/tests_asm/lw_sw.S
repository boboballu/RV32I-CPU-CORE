# # check all load store ops
# # change sw output to hex in testbench to check easily
# # SW ops
# addi x2 x0 254
# sw x2 80(x0)
# addi x2 x0 3
# sb x2 80(x0)
# sb x2 81(x0)
# sb x2 82(x0)
# sb x2 83(x0)

# sh x2 80(x0)
# sh x2 82(x0)

# sw x0 84(x0) # simulation stops here

lui x2 10000
addi x2 x2 2000
addi x4 x0 0

sw x2 800(x0)
lw x4, 800(x0)
sw x4, 400(x0)

lb x4 800(x0)
sw x4, 400(x0)

lb x4, 801(x0)
sw x4, 400(x0)

lbu x4 802(x0)
sw x4, 400(x0)

lhu x4 802(x0)
sw x4, 400(x0)

lh x4 800(x0)
sw x4, 400(x0)
