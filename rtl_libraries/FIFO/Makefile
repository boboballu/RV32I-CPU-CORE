sim_ready_valid: compile
	vsim ready_valid_tb

sim_fifo: compile
	vsim -do "do wave.do;" fifo_tb

compile:
	vlog FIFO.sv
	vlog FIFO_tb.sv
	vlog ready_valid_tb.sv
	vlog ready_valid.sv

clean:
	rm -rf work
	rm -rf *.vcd
