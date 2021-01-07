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
	../tb_debug_package.sv \
	../rtl_instn_decode.sv \
	../rtl_branch_compute.sv \
	../rtl_comb_stages.sv \
	../rtl_ff_stages.sv \
	../rtl_controller.sv \
	../rtl_hazard_unit.sv \
	../rtl_BTB.sv \
	../rtl_bpred.sv \
	../rtl_core_top.sv \
	../rtl_memory_impl.sv \
	../rtl_top_test.sv \
	--top-module top --trace -exe ../emulator/emulator.cc ../emulator/emulator_child.cc ../tb_functions.cc ../tb.cc -Mdir verilator_tb
	make -C verilator_tb -f Vtop.mk
	echo "\nTo run : make run exe=#.dat_file_path case=#{1,2,3}#1_rtl 2_emu 3_rtl emu compare | default : make run\n"

run:
	./verilator_tb/Vtop +EXEC=$(exe) $(exe) $(case)

clean:
	rm -rf verilator_tb
	rm -rf dump *.log