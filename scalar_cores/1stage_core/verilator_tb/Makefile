# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
# ****************************************************************************** #
# manual: https://www.veripool.org/wiki/verilator/Manual-verilator
case?=3
exe?=../memfile.dat
#WARNING=-Wall
WARNING=
verilate:
	verilator $(WARNING) -Wno-fatal -I../ --cc \
	../debug_package.sv \
	../controller_if.sv \
	../datapath.sv \
	../controller.sv \
	../core_top.sv \
	../L1_cache.sv \
	../top_test.sv \
	--top-module top --trace -exe ../emulator/emulator.cc ../emulator/emulator_child.cc ../tb_functions.cc ../tb.cc -Mdir verilator_tb
	make -C verilator_tb -f Vtop.mk
	echo "\nTo run : make run exe=#.dat_file_path case=#{1,2,3}#1_rtl 2_emu 3_rtl emu compare | default : make run\n"


run:
	./verilator_tb/Vtop +EXEC=$(exe) $(exe) $(case)

clean:
	rm -rf verilator_tb
