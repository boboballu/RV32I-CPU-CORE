#Author: Tarun Govind Kesavamurthi
#School: North Carolina State University
#mail  : tkesava@ncsu.edu
#********************************************************************************
tf ?= ./trace_test.txt

all: compile run

cli: clean compile
	vsim -c -do "run -all; exit" +TF=$(tf) tb

compile:
	vlog cache.sv
	vlog cache_tb.sv

run:
	vsim -do "do wave.do" +TF=$(tf) tb

clean:
	rm -rf work
