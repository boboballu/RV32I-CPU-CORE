# manual: https://www.veripool.org/wiki/verilator/Manual-verilator
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
	--top-module top --trace -exe ../testbench.cc -Mdir verilator_tb
	make -C verilator_tb -f Vtop.mk

run:
	./verilator_tb/Vtop +EXEC=../memfile.dat

clean:
	rm -rf verilator_tb
