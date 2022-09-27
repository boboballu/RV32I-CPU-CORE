cli: clean compile
	vsim -c -do "run -all; exit" async_fifo_ready_valid_tb

gui: clean compile
	vsim -do "do wave.do;" async_fifo_ready_valid_tb

compile:
	vlog binary_gray_converters.sv
	vlog sync.sv
	vlog ready_valid_if.sv
	vlog async_fifo.sv
	vlog async_fifo_tb.sv

clean:
	rm -rf work
	rm -rf *.vcd
