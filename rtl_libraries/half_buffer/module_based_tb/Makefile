cli: clean compile
	vsim -c -do "run -all; exit" valid_ready_tb

gui: clean compile
	vsim -do "do wave.do;" valid_ready_tb

compile: rtl tb

# [EDIT*] add RTL
rtl:
	vlog ../rtl/valid_ready_if.sv
	vlog ../rtl/half_buffer.sv
	vlog ../rtl/valid_ready.sv

tb:
	vlog datatypes_globals_pkg.sv
	vlog valid_ready_tb_elements.sv
	vlog valid_ready_tb.sv

clean:
	rm -rf work
	rm -rf *.vcd

clean_all: clean
	rm -rf transcript
	rm -rf vsim.wlf