#Author: Tarun Govind Kesavamurthi
#School: North Carolina State University
#mail  : tkesava@ncsu.edu
#********************************************************************************
exe ?= ./memfile.dat
d_addr ?= 84
d_data ?= 7
df ?= h
cli: clean work compile
	vsim -c -do "run -all; exit" +df=$(df) +EXEC=$(exe) +D_cache_address=$(d_addr) +D_cache_data=$(d_data) testbench

all: clean work compile run

run:
	vsim -novopt +EXEC=$(exe) +D_cache_address=$(d_addr) +D_cache_data=$(d_data) testbench

compile:
	vlog -sv -lint debug.svh
	vlog -sv -lint controller_if.sv
	vlog -sv -lint datapath.sv
	vlog -sv -lint controller.sv
	vlog -sv -lint core_top.sv
	vlog -sv -lint top_test.sv
	vlog -sv -lint testbench.sv

work:
	vlib work

clean:
	rm -rf work *.wlf transcript