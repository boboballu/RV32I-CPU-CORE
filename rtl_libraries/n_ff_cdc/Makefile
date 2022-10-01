mux_sync_cli: clean compile
	vsim -c -do "run -all; exit" mux_sync_tb

mux_sync_gui: clean compile
	vsim mux_sync_tb

m_ff_sync_cli: clean compile
	vsim -c -do "run -all; exit" m_ff_sync_tb

m_ff_gui: clean compile
	vsim m_ff_sync_tb

compile:
	vlog m_ff_sync.sv
	vlog mux_sync.sv
	vlog m_ff_sync_tb.sv
	vlog mux_sync_tb.sv

clean:
	rm -rf work
	rm -rf *.vcd