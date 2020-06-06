#Author: Tarun Govind Kesavamurthi
#School: North Carolina State University
#mail  : tkesava@ncsu.edu
#********************************************************************************
cli: clean work compile
	vsim -c -do "run -all; exit;" testbench 
all: clean work compile run
run:
	vsim -novopt testbench
compile:
	vlog -sv datapath.sv
	vlog -sv controller.sv
	vlog -sv core_top.sv
	vlog -sv testbench.sv
work:
	vlib work
clean:
	rm -rf work *.wlf transcript