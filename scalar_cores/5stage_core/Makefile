# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
#********************************************************************************#

exe ?= ./test_executables/riscvtest.dat
d_addr ?= 84
d_data ?= 7

cli: clean work compile
	vsim -c -do "run -all; exit" +EXEC=$(exe) +D_cache_address=$(d_addr) +D_cache_data=$(d_data) testbench

all: clean work compile testbench

compile: packages design all_tbs

design:
	vlog -sv comb_stages.sv
	vlog -sv ff_stages.sv
	vlog -sv controller.sv
	vlog -sv hazard_unit.sv
	vlog -sv main.sv

packages: 
	vlog -sv packages.sv

all_tbs:
	vlog -sv top_test.sv
	vlog -sv testbench.sv

testbench:
	vsim -novopt +EXEC=$(exe) +D_cache_address=$(d_addr) +D_cache_data=$(d_data) testbench

work:
	vlib work

clean:
	rm -rf work *.wlf transcript
