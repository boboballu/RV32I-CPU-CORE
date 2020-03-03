all: clean work compile run
compile:
	vlog -sv comb_stages.sv
	vlog -sv ff_stages.sv
	vlog -sv controller.sv
	vlog -sv hazard_unit.sv
	vlog -sv main.sv
	vlog -sv testbench.sv
run:
	vsim testbench
work:
	vlib work
clean:
	rm -rf work *.wlf transcript