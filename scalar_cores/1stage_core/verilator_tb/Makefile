# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
# ****************************************************************************** #
# manual: https://www.veripool.org/wiki/verilator/Manual-verilator
case?=3
exe?=../firmware32.hex
#WARNING=-Wall
WARNING=
verilate:
	verilator $(WARNING) -Wno-fatal -I../ --cc \
	../tb_debug_package.sv \
	../rtl_controller_if.sv \
	../rtl_datapath.sv \
	../rtl_controller.sv \
	../rtl_core_top.sv \
	../rtl_memory_impl.sv \
	../rtl_top_test.sv \
	--top-module top --trace -exe ../emulator/emulator.cc ../emulator/emulator_child.cc ../tb_functions.cc ../tb.cc -Mdir verilator_tb
	make -C verilator_tb -f Vtop.mk
	echo "\nTo run : make run exe=*32.hex case=#{1,2,3} \n#1_rtl 2_emu 3_rtl emu compare | default : make run\n"


run:
	./verilator_tb/Vtop +EXEC=$(exe) $(exe) $(case)

clean:
	rm -rf verilator_tb
	rm -rf dump *.log
