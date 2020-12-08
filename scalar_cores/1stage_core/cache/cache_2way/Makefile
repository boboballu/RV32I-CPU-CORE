all: compile run
compile:
	vlog cache_2way.sv
	vlog cache_2way_tb.sv
run:
	vsim tb
clean:
	rm -rf work
