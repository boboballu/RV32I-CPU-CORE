TEST ?= 1

cli: clean compile
	vsim -c -do "run -all; exit" +test=$(TEST) valid_ready_tb

gui: clean compile
	vsim -do "do wave.do;" +test=$(TEST) valid_ready_tb

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
	
help:
	$(info make TEST=\{0: PERFECT_SENDER_RECEIVER, 1: BUSY_RECEIVER, 2: RANDOM\} | defaults to 1)
	$(info eg: make TEST=2)