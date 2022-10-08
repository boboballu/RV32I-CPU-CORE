test ?= 2

cli: clean compile
	vsim -c -do "run -all; exit" +test=$(test) ready_valid_tb

gui: clean compile
	vsim -do "do wave.do;" +test=$(test) ready_valid_tb

compile: rtl tb

rtl:
	vlog ../ready_valid_if.sv
	vlog ../fifo.sv
	vlog ../valid_credit.sv

tb:
	vlog ready_valid_tb.sv

clean:
	rm -rf work
	rm -rf *.vcd

clean_all: clean
	rm -rf transcript
	rm -rf vsim.wlf