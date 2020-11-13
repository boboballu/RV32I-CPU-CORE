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
	../packages.sv \
	../instn_decode.sv \
	../branch_compute.sv \
	../comb_stages.sv \
	../ff_stages.sv \
	../controller.sv \
	../hazard_unit.sv \
	../BTB.sv \
	../Bpred.sv \
	../main.sv \
	../L1_cache.sv \
	../top_test.sv \
	--top-module top --trace -exe ../emulator/emulator.cc ../emulator/emulator_child.cc ../tb_functions.cc ../tb.cc -Mdir verilator_tb
	make -C verilator_tb -f Vtop.mk
	echo "\nTo run : make run exe=#.dat_file_path case=#{1,2,3}#1_rtl 2_emu 3_rtl emu compare | default : make run\n"

run:
	./verilator_tb/Vtop +EXEC=$(exe) $(exe) $(case)

clean:
	rm -rf verilator_tb
	rm -rf dump *.log