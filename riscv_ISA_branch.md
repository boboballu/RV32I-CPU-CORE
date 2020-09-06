# This branch is for the riscv - rv32I implementation.
* rv32I_noCSR_noFence implementation | 32 instns implemented; Compiler flags -march=rv32i -mabi=ilp32 | newlib riscv port not tested
* riscv directory containes the riscv isa manual 2.2 and the ripes classical 5 stage riscv processor simulator
* scalar_cores have 1stage and 5stage core implementation

# 5stage_core_riscv
* 5 stage pipelined | CSR regs / instns and FENCE ANF FENCEi TBI
* has optional BTB and a simple bimodal branch predictor
* Optional LS queue - TBI

