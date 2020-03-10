# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
#********************************************************************************#

cli: clean work compile
	vsim -c -do "run -all; exit" testbench

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
	vlog -sv testcase1.sv
	vlog -sv testcase2.sv
	vlog -sv testcase3.sv
	vlog -sv testbench.sv

testcase1:
	vsim -novopt testcase1
testcase2:
	vsim -novopt testcase2
testcase3:
	vsim -novopt testcase3
testbench:
	vsim -novopt testbench

work:
	vlib work

clean:
	rm -rf work *.wlf transcript