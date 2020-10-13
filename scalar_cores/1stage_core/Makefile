#Author: Tarun Govind Kesavamurthi
#School: North Carolina State University
#mail  : tkesava@ncsu.edu
#********************************************************************************
exe ?= ./memfile.dat

# Enable lint
#lint=-lint
# Disable lint
lint=

cli: clean work compile
	vsim -c -do "run -all; exit" +EXEC=$(exe) testbench

gui: clean work compile
	vsim -novopt +EXEC=$(exe) testbench

gui_opt: clean work compile
	vsim +EXEC=$(exe) testbench

compile:
	vlog -sv $(lint) debug_package.sv
	vlog -sv $(lint) controller_if.sv
	vlog -sv $(lint) datapath.sv
	vlog -sv $(lint) controller.sv
	vlog -sv $(lint) core_top.sv
	vlog -sv $(lint) L1_cache.sv
	vlog -sv $(lint) top_test.sv
	vlog -sv $(lint) testbench.sv

work:
	vlib work

clean:
	rm -rf work *.wlf transcript
