# Author: Tarun Govind Kesavamurthi
#  School: North Carolina State University
#  mail  : tkesava@ncsu.edu
# /********************************************************************************/
CC=g++
CFLAGS=-g
DEPS = execute_instn.cc main.cc
OBJ = execute_instn.o main.o
%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

emulator: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	rm -rf *.o emulator
