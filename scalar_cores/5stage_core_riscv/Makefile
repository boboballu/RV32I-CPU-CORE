# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
#********************************************************************************#

exe ?= ./firmware32.hex

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

compile: pkg compile_rtl compile_tb

pkg:
	vlog -sv $(lint) tb_debug_package.sv

compile_rtl:
	vlog -sv $(lint) rtl_instn_decode.sv
	vlog -sv $(lint) rtl_branch_compute.sv
	vlog -sv $(lint) rtl_comb_stages.sv
	vlog -sv $(lint) rtl_ff_stages.sv
	vlog -sv $(lint) rtl_controller.sv
	vlog -sv $(lint) rtl_hazard_unit.sv
	vlog -sv $(lint) rtl_BTB.sv
	vlog -sv $(lint) rtl_bpred.sv
	vlog -sv $(lint) rtl_core_top.sv
	vlog -sv $(lint) rtl_memory_impl.sv
	vlog -sv $(lint) rtl_top_test.sv

compile_tb:	
	vlog -sv $(lint) tb_testbench.sv

work:
	vlib work

clean:
	rm -rf work *.wlf transcript
