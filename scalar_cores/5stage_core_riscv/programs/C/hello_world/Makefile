## Author: Tarun Govind Kesavamurthi
## School: North Carolina State University
## mail  : tkesava@ncsu.edu
##*******************************************************************************##

## can use both gcc and g++;
##Personally I feel there is no difference between gcc and g++ these days

## Baremetal binary with math (Arthmetic) libraries
## https://stackoverflow.com/questions/57021029/how-to-link-math-library-when-building-bare-metal-application-with-custom-linker

cc=riscv64-unknown-elf-g++
objdump = riscv64-unknown-elf-objdump
objcopy = riscv64-unknown-elf-objcopy
# cc=riscv-none-embed-g++
# objdump = riscv-none-embed-objdump
# objcopy = riscv-none-embed-objcopy

# OLD Compiler Args - Grendel
CFLAGS=-m32 -march=RV32I
# NEW Compiler Args - Personal Machine
#CFLAGS=-march=rv32i -mabi=ilp32
OPT=-O1
ccFs:=main.cc init1.cc
ASMs:=init.s
OBJ:=init.o init1.o main.o

exe: $(OBJ)
	$(cc) -o $@ $^ $(CFLAGS) -Xlinker -T -Xlinker link.ld -nostdlib -nostartfiles -ffreestanding -lgcc

%.o: %.cc $(ccFs)
	$(cc) -c -o $@ $< $(OPT) $(CFLAGS) -nostdlib -nostartfiles -ffreestanding

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
