**N way set associative cache README**
**Author: Tarun Govind Kesavamurthi**

*Understanding my file Prefixes*
* "rtl_*"     RTL source files
* "tb_*"      Test bench files
* "pkg*"      All Package files
    * "pkg_rtl*"  RTL package files
    * "pkg_tb*"   TB package files
* "defs_params_common"    svh - header file with all common defs and params

*Directories*
* "verilator_tb"  Containes verilator testbench
(Verilator tb is not complete and not necessary for cache since 
metric generation is already added to the tb_cache.sv)