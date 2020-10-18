# tkesava - modelsim 20.2 installation in riscv container is a free edition
# it doesnt have FPI / DPI enabled hence it wont work
mydpi:
	vlib work
	vlog tb.sv
	gcc -m32 -fPIC -g -w -shared -I /opt/intelFPGA_pro/20.2/modelsim_ase/include/ -Lstdc++ my_dpi.cpp -o my_dpi.so
	vsim -dpicpppath /usr/bin/gcc -c test -do "run -all; quit" -sv_lib my_dpi

# in grendel
dpi:
	vlib work
	vlog tb.sv my_dpi.cpp
	vsim -c test -do "run -all; quit"
