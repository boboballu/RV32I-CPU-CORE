#Author: Tarun Govind Kesavamurthi
#School: North Carolina State University
#mail  : tkesava@ncsu.edu
#********************************************************************************
exe ?= ./memfile32.hex

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

pkg:
	vlog -sv $(lint) tb_debug_package.sv

compile_rtl:
	vlog -sv $(lint) rtl_controller_if.sv
	vlog -sv $(lint) rtl_datapath.sv
	vlog -sv $(lint) rtl_controller.sv
	vlog -sv $(lint) rtl_core_top.sv
	vlog -sv $(lint) rtl_memory_impl.sv
	vlog -sv $(lint) rtl_top_test.sv

compile_tb:
	vlog -sv $(lint) tb_testbench.sv

compile: pkg compile_rtl compile_tb

work:
	vlib work

clean:
	rm -rf work *.wlf transcript
