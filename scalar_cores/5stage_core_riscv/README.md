**5 Stage pipelined RV32I compliant CPU Core**
**Author: Tarun Govind Kesavamurthi**

*Understanding my file Prefixes*
* "rtl_*"                   RTL source files
* "tb_*"                    Test bench files
* "pkg*"                    All Package files
    * "pkg_rtl*"                RTL package files
    * "pkg_tb*"                 TB package files
* "defs_params_common"      svh - header file with all common defs and params
* "ni_*"                    Files not implemented / not important / or has no importance what-so-ever 

*Directories*
* "verilator_tb"  Containes verilator testbench

*Riscv executables*
* "*32.hex"                 Riscv executable, each line is 32bit hex which fills the memory. Use at makefile $exe arg to pass any hex as input 
