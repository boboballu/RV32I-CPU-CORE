# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
#********************************************************************************#
all: clean work compile testcase1
compile:
	vlog -sv comb_stages.sv
	vlog -sv ff_stages.sv
	vlog -sv controller.sv
	vlog -sv hazard_unit.sv
	vlog -sv main.sv
	vlog -sv testbench.sv
	vlog -sv testcase1.sv

testcase1:
	vsim -novopt testcase1
run:
	vsim -novopt testbench
work:
	vlib work
clean:
	rm -rf work *.wlf transcript