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
	../cache.sv \
	--top-module cache_module --trace -exe ../testbench.cc -Mdir verilator_tb
	make -C verilator_tb -f Vtop.mk
	# echo "\nTo run : make run exe=#.dat_file_path case=#{1,2,3}#1_rtl 2_emu 3_rtl emu compare | default : make run\n"

run:
	./verilator_tb/Vtop +EXEC=$(exe) $(exe) $(case)

clean:
	rm -rf verilator_tb
	rm -rf dump *.log
