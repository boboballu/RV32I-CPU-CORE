# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
#********************************************************************************#

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

compile: packages design all_tbs

design:
	vlog -sv $(lint) instn_decode.sv
	vlog -sv $(lint) branch_compute.sv
	vlog -sv $(lint) comb_stages.sv
	vlog -sv $(lint) ff_stages.sv
	vlog -sv $(lint) controller.sv
	vlog -sv $(lint) hazard_unit.sv
	vlog -sv $(lint) BTB.sv
	vlog -sv $(lint) Bpred.sv
	vlog -sv $(lint) main.sv
	vlog -sv $(lint) L1_cache.sv

packages:
	vlog -sv $(lint) packages.sv

all_tbs:
	vlog -sv $(lint) top_test.sv
	vlog -sv $(lint) testbench.sv

work:
	vlib work

clean:
	rm -rf work *.wlf transcript
