cli: clean compile
	vsim -c -do "run -all; exit" async_fifo_valid_ready_tb

gui: clean compile
	vsim -do "do wave.do;" async_fifo_valid_ready_tb

compile:
	vlog ../rtl/binary_gray_converters.sv
	vlog ../rtl/m_ff_sync.sv
	vlog ../rtl/valid_ready_if.sv
	vlog ../rtl/async_fifo.sv
	vlog async_fifo_tb.sv

clean:
	rm -rf work
	rm -rf *.vcd
