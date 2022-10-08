cli: clean compile
	vsim -c -do "run -all; exit" fifo_valid_ready_tb

gui: clean compile
	vsim -do "do wave.do;" fifo_valid_ready_tb

compile: rtl tb

rtl:
	vlog ../rtl/valid_ready_if.sv
	vlog ../rtl/fifo.sv

tb:
	vlog fifo_tb.sv

clean:
	rm -rf work
	rm -rf *.vcd

clean_all: clean
	rm -rf transcript
	rm -rf vsim.wlf
