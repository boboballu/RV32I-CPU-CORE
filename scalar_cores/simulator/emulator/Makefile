# Author: Tarun Govind Kesavamurthi
#  School: North Carolina State University
#  mail  : tkesava@ncsu.edu
# /********************************************************************************/
cc=g++
CFLAGS=-O0 -g
DEPS = emulator.cc emulator_child.cc main.cc
OBJ = emulator.o emulator_child.o main.o

%.o: %.cc $(DEPS)
	$(cc) -c -o $@ $< $(CFLAGS)

emulator: $(OBJ)
	$(cc) -o $@ $^ $(CFLAGS)
clean:
	rm -rf *.o emulator
