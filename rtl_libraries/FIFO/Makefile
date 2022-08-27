all: compile run
compile:
	vlog FIFO.sv
	vlog FIFO_tb.sv
run:
	vsim fifo_tb
clean:
	rm -rf work
	rm -rf *.vcd
