CC=riscv64-unknown-elf-gcc
# CFLAGS=-O0 -m32 -march=RV32I
CFLAGS=-O3 -march=rv32i -mabi=ilp32
CCFs:=main.cc
ASMs:=init.s
OBJ:=init.o main.o 

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -T link.ld -nostdlib

%.o: %.cc $(CCFs)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.s $(ASMs)
	$(CC) -c -o $@ $< $(CFLAGS)

dsm:
	riscv64-unknown-elf-objdump -D exe > exe.dump
bin:
	riscv64-unknown-elf-objcopy -O binary --only-section=.text* --only-section=.rodata* --only-section=.data* exe exe.bin
dat:	
	hexdump -v -e '"%08x\n"' exe.bin > exe.dat

all: exe dsm bin dat
clean:
	rm -rf *.o exe exe.*
