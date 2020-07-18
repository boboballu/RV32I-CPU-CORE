# manual: https://www.veripool.org/wiki/verilator/Manual-verilator
verilate:
	verilator -Wno-fatal -I../ --cc \
	../debug.svh \
	../controller_if.sv \
	../datapath.sv \
	../controller.sv \
	../core_top.sv \
	../top_test.sv \
	--top-module top --trace -exe ../testbench.cc -Mdir verilator_tb

clean:
	rm -rf verilator_tb