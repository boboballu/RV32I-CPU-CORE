#lui test
lui a1 1        # a1 = 4096
lui a2 2        # a2 = 8192
sub a3 a1 a2    # a3 = 4096 - 8192 = -4096
add a4 a1 a2    # a4 = 4096 + 8192 = 12288
sw a4 100(x0)   # mem[100] = 12288
sw a3 84(x0)    # mem[84] = -4096

