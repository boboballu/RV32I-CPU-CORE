# riscv-none-embed-g++ -march=rv32i -mabi=ilp32 -MD -Os -Wall -std=c++11 -c -o firmware.o firmware.cc
# riscv-none-embed-gcc -march=rv32i -mabi=ilp32 -MD -Os -Wall -c -o syscalls.o syscalls.c
# riscv-none-embed-gcc -march=rv32i -mabi=ilp32 -Wl,--gc-sections -o firmware.elf firmware.o syscalls.o -T ../../firmware/riscv.ld -lstdc++

RISCV_TOOLS_PREFIX = riscv-none-embed-
CC = $(RISCV_TOOLS_PREFIX)gcc
CPP = $(RISCV_TOOLS_PREFIX)g++
objdump = $(RISCV_TOOLS_PREFIX)objdump
OPT=-O

ccFs=
cFs=syscalls.c
ASMs=start.S
OBJ=start.o syscalls.o

include makevars.mk

ARCHFLAGS=-march=rv32i -mabi=ilp32
CFLAGS=$(ARCHFLAGS) -MD -Os -Wall
CCFLAGS=$(CFLAGS) -std=c++11
LDFLAGS=$(ARCHFLAGS) -Wl,--gc-sections -T riscv.ld -lstdc++

firmware32.hex: firmware.elf hex8tohex32.py
	$(RISCV_TOOLS_PREFIX)objcopy -O verilog firmware.elf firmware.hex
	python3 hex8tohex32.py firmware.hex > firmware32.hex

firmware.dump: firmware.elf
	$(objdump) -D $< > $@

firmware.elf: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cc $(ccFs)
	$(CPP) -c -o $@ $< $(OPT) $(CCFLAGS)

%.o: %.c $(cFs)
	$(CC) -c -o $@ $< $(OPT) $(CFLAGS)

%.o: %.S $(ASMs)
	$(CC) $(ARCHFLAGS) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o *.d
	rm -f *.elf *.hex
