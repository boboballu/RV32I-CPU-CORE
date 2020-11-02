# This branch is for the riscv - rv32I implementation.
* rv32I implementation, no CSR and Fence instns implemented | Compiler flags -march=rv32i -mabi=ilp32 | newlib riscv port not tested
* riscv directory containes the riscv isa manual 2.2 and other relevant documentation
* scalar_cores have 1stage and 5stage core implementation

# 5stage_core_riscv
* 5 stage pipelined | CSR regs / instns and FENCE ANF FENCEi TBI (No interrupts)
* has optional BTB and a simple bimodal branch predictor
* Optional LS queue - TBI

