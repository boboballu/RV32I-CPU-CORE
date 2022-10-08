cli: clean compile
	vsim -c -do "run -all; exit" ready_valid_tb

gui: clean compile
	vsim -do "do wave.do;" ready_valid_tb

compile: rtl tb

rtl:
	vlog ../rtl/ready_valid_if.sv
	vlog ../rtl/fifo.sv
	vlog ../rtl/valid_credit.sv

tb:
	vlog datatypes_globals_pkg.sv
	vlog ready_valid_tb_elements.sv
	vlog ready_valid_tb.sv

clean:
	rm -rf work
	rm -rf *.vcd

clean_all: clean
	rm -rf transcript
	rm -rf vsim.wlf