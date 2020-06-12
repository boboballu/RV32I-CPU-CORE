# check all load store ops
# change sw output to hex in testbench to check easily
# SW ops
addi x2 x0 256
sw x2 80(x0)
addi x2 x0 3
sb x2 80(x0)
sb x2 81(x0)
sb x2 82(x0)
sb x2 83(x0)

sw x0 80(x0)
sh x2 80(x0)
sh x2 82(x0)

sw x0 84(x0) # simulation stops here


