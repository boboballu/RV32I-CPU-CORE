cli: clean compile
	vsim -c -do "run -all; exit" clk_divider_tb

gui: clean compile
	vsim -do "do wave.do;" clk_divider_tb

compile:
	vlog clk_divider.sv
	vlog clk_divider_tb.sv

clean:
	rm -rf work
	rm -rf *.vcd
