sim_ready_valid: compile
	vsim -do "do ready_valid_if.do;" ready_valid_tb

sim_fifo: compile
	vsim -do "do wave.do;" fifo_tb

compile:
	vlog ready_valid_if.sv
	vlog fifo.sv
	vlog fifo_tb.sv
	vlog ready_valid_tb.sv
	vlog ready_valid.sv

clean:
	rm -rf work
	rm -rf *.vcd
