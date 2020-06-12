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
	vlog -sv datapath.sv
	vlog -sv controller.sv
	vlog -sv core_top.sv
	vlog -sv testbench.sv

work:
	vlib work

clean:
	rm -rf work *.wlf transcript