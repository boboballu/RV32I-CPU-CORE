# manual: https://www.veripool.org/wiki/verilator/Manual-verilator
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
	--top-module top --trace -exe ../testbench.cc -Mdir verilator_tb
	make -C verilator_tb -f Vtop.mk

run:
	./verilator_tb/Vtop +EXEC=../memfile.dat

clean:
	rm -rf verilator_tb
