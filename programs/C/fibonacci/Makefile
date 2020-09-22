cc=riscv64-unknown-elf-gcc
objdump = riscv64-unknown-elf-objdump
objcopy = riscv64-unknown-elf-objcopy
# CFLAGS=-O0 -m32 -march=RV32I
CFLAGS=-march=rv32i -mabi=ilp32
OPT=-O0
ccFs:=main.cc #init.cc
ASMs:=init.s
OBJ:=init.o main.o 

exe: $(OBJ)
	$(cc) -o $@ $^ $(CFLAGS) -T link.ld -nostdlib

%.o: %.cc $(ccFs)
	$(cc) -c -o $@ $< $(OPT) $(CFLAGS)

%.o: %.s $(ASMs)
	$(cc) -c -o $@ $< $(CFLAGS)

dsm_from_dat:
	sed 's/^/.word 0x/' exe.dat > disassembly.s
	$(cc) -c disassembly.s
	$(objdump) -d disassembly.o > disassembly.dump

dsm_from_elf:
	$(objdump) -D exe > exe.dump

spike_dsm:
	sed 's/.*/DASM(0x&)/' exe.dat > spike_dsm.dat
	cat spike_dsm.dat | spike-dasm > spike_dsm.dump

bin:
	$(objcopy) -O binary --only-section=.text* --only-section=.rodata* --only-section=.data* exe exe.bin

dat:	
	hexdump -v -e '"%08x\n"' exe.bin > exe.dat

all: exe dsm_from_elf bin dat dsm_from_dat

clean:
	rm -rf *.o exe exe.* disassembly.*
