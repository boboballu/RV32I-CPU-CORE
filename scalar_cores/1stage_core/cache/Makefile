#Author: Tarun Govind Kesavamurthi
#School: North Carolina State University
#mail  : tkesava@ncsu.edu
#********************************************************************************
tf ?= ./trace_test.txt

all: compile run

cli: clean compile
	vsim -c -do "run -all; exit" +TF=$(tf) tb

compile_rtl:
	vlog pkg_rtl_cache_types.sv
	vlog rtl_cache.sv

compile_tb:
	vlog tb_memory_models.sv
	vlog tb_cache.sv

compile: compile_rtl compile_tb

run:
	vsim -sv_seed 12345 -do "do wave.do" +TF=$(tf) tb

clean:
	rm -rf work
