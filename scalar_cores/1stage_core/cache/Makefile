all: compile run
compile:
	vlog cache_new.sv
	vlog cache_tb.sv
run:
	vsim tb
clean:
	rm -rf work
