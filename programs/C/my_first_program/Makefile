## Author: Tarun Govind Kesavamurthi
## School: North Carolina State University
## mail  : tkesava@ncsu.edu
##*******************************************************************************##

## can use both gcc and g++; 
##Personally I feel there is no difference between gcc and g++ these days
cc=riscv64-unknown-elf-g++
objdump = riscv64-unknown-elf-objdump
objcopy = riscv64-unknown-elf-objcopy
# CFLAGS=-O0 -m32 -march=RV32I
CFLAGS=-march=rv32i -mabi=ilp32
OPT=-O3
ccFs:=main.cc
ASMs:=init.s
OBJ:=init.o main.o 

exe: $(OBJ)
	$(cc) -o $@ $^ $(CFLAGS) -T link.ld -nostdlib

%.o: %.cc $(ccFs)
	$(cc) -c -o $@ $< $(OPT) $(CFLAGS)

%.o: %.s $(ASMs)
	$(cc) -c -o $@ $< $(CFLAGS)

disassembly.dump:
	sed 's/^/.word 0x/' exe.dat > disassembly.s
	$(cc) -c disassembly.s
	$(objdump) -d disassembly.o > disassembly.dump

exe.dump:
	$(objdump) -D exe > exe.dump

exe.bin:
	$(objcopy) -O binary --only-section=.text* --only-section=.rodata* --only-section=.data* exe exe.bin

exe.dat:	
	hexdump -v -e '"%08x\n"' exe.bin > exe.dat

all: exe exe.dump exe.bin exe.dat disassembly.dump

clean:
	rm -rf *.o exe exe.* disassembly.*
