cli: clean compile
	vsim -c -do "run -all; exit" async_fifo

gui: clean compile
	vsim -do "do wave.do;" async_fifo

compile:
	vlog aync_fifo.sv
	vlog ready_valid_if.sv
	vlog async_fifo_tb.sv

clean:
	rm -rf work
	rm -rf *.vcd
