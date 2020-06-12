CC=riscv64-unknown-elf-gcc
CFLAGS=-O3 -m32 -march=RV32I
CCFs = main.cc
ASMs = init.s
OBJ = init.o main.o
%.o: %.cc $(CCFs)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.s $(ASMs)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -T link.ld -nostdlib

dsm:
	riscv64-unknown-elf-objdump -S -s exe > exe.dump
bin:
	riscv64-unknown-elf-objcopy -O binary --only-section=.data* --only-section=.text* exe exe.bin
dat:	
	hexdump -v -e '"%08x\n"' exe.bin > exe.dat

all: exe dsm bin dat
clean:
	rm -rf *.o exe exe.*
