cli: clean compile
	vsim -c -do "run -all; exit" fifo_ready_valid_tb

gui: clean compile
	vsim -do "do wave.do;" fifo_ready_valid_tb

compile:
	vlog ready_valid_if.sv
	vlog fifo.sv
	vlog fifo_tb.sv

clean:
	rm -rf work
	rm -rf *.vcd
