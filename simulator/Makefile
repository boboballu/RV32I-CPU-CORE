CC=g++
CFLAGS=-g
DEPS = simulator.cc funct_sim.cc
OBJ = simulator.o funct_sim.o
%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sim: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	rm -rf *.o sim