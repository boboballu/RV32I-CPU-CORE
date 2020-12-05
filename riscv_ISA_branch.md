*Author : Tarun Govind Kesavamurthi* |
*School : North Carolina State University - Comp Engg* |
*EMAIL  : tkesava@ncsu.edu*

# "riscv_ISA" - rv32I implementation.
* rv32I implementation, no CSR and Fence instns implemented | Compiler flags -march=rv32i -mabi=ilp32 | newlib riscv port tested
* riscv directory containes the riscv isa manual 2.2 and other relevant documentation
* scalar_cores have the core - RTL implementation

# 5stage_core_riscv
* 5 stage pipelined core | CSR regs/instns, FENCE ANF FENCEi TBI (No interrupts as of now)
* has optional BTB and a simple bimodal branch predictor
* Parametrizable L1 cache implementation - TBI
* Optional LS queue - TBI

# riscv DIR
* Contains core documentation (pptx), and RISCV ISA specifications

# running newlib programs
* in Programs/newlib dir, create a new folder, add the .cc or .c source file, 
ln -s ../common/* .
add the .cc and .o files in makevars.mk file, and run make
* **Running firmware32.hex** - Copy firmware32.hex in scalar_cores/5stage_core_riscv (or specify the path during make)
enter scalar_cores/5stage_core_riscv/verilator_tb, make and make run exe=../firmware32.hex case=1
* see the case options for running the firmware32.hex in rtl, emulator or a rtl-emulator comparitive run.