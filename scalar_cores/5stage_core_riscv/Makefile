# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
#********************************************************************************#

exe ?= ./memfile.dat
d_addr ?= 84
d_data ?= 7

cli: clean work compile
	vsim -c -do "run -all; exit" +EXEC=$(exe) +D_cache_address=$(d_addr) +D_cache_data=$(d_data) testbench

all: clean work compile testbench

compile: packages design all_tbs

design:
	vlog -sv instn_decode.sv
	vlog -sv branch_compute.sv
	vlog -sv comb_stages.sv
	vlog -sv ff_stages.sv
	vlog -sv controller.sv
	vlog -sv hazard_unit.sv
	vlog -sv BTB.sv
	vlog -sv Bpred.sv
	vlog -sv main.sv
	vlog -sv L1_cache.sv
packages: 
	vlog -sv packages.sv

all_tbs:
	vlog -sv top_test.sv
	vlog -sv testbench.sv

testbench:
	vsim +EXEC=$(exe) +D_cache_address=$(d_addr) +D_cache_data=$(d_data) testbench

work:
	vlib work

clean:
	rm -rf work *.wlf transcript
