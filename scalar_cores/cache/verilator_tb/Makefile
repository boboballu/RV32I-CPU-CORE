# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
# ****************************************************************************** #
# manual: https://www.veripool.org/wiki/verilator/Manual-verilator
tf?=../gcc_trace.txt
#WARNING=-Wall
WARNING=
verilate:
	verilator $(WARNING) -Wno-fatal -I../ --cc \
	../pkg_rtl_cache_types.sv \
	../rtl_cache.sv \
	../tb_memory_models.sv \
	../tb_cache.sv \
	--top-module tb --trace -exe ../testbench.cc -Mdir verilator_tb
	make -C verilator_tb -f Vtop.mk
	# echo "\nTo run : make run exe=#.dat_file_path case=#{1,2,3}#1_rtl 2_emu 3_rtl emu compare | default : make run\n"

run:
	./verilator_tb/Vtop +TF=$(exe)

clean:
	rm -rf verilator_tb
	rm -rf dump *.log
