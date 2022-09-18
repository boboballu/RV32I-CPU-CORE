cli: clean compile
	vsim -c -do "run -all; exit" ready_valid_tb

gui: cclean ompile
	vsim -do "do ready_valid_if.do;" ready_valid_tb

compile:
	vlog ready_valid_if.sv
	vlog fifo.sv
	vlog ready_valid.sv
	vlog ready_valid_tb.sv

clean:
	rm -rf work
	rm -rf *.vcd
