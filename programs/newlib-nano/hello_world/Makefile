## Author: Tarun Govind Kesavamurthi
## School: North Carolina State University
## mail  : tkesava@ncsu.edu
##*******************************************************************************##

## can use both gcc and g++;
##Personally I feel there is no difference between gcc and g++ these days

## Baremetal binary with math (Arthmetic) libraries
## https://stackoverflow.com/questions/57021029/how-to-link-math-library-when-building-bare-metal-application-with-custom-linker
allSectionsDir = ./sections
## riscv official compiler binaries - with multilib support
# cc=riscv64-unknown-elf-gcc
# objdump = riscv64-unknown-elf-objdump
# objcopy = riscv64-unknown-elf-objcopy
# strip	= riscv64-unknown-elf-strip


## riscv xpack installer - binaries
## https://xpack.github.io/riscv-none-embed-gcc/install/
cc=riscv-none-embed-g++
objdump = riscv-none-embed-objdump
objcopy = riscv-none-embed-objcopy
strip	= riscv-none-embed-strip

# OLD Compiler Args - Grendel
#CFLAGS=-m32 -march=RV32I
# NEW Compiler Args - Personal Machine
CFLAGS=-march=rv32i -mabi=ilp32 -lc
LDFLAGS=-march=rv32i -mabi=ilp32 -lc --specs=nosys.specs -Xlinker -T -Xlinker link.ld -Wl,-Map=exe.map,--no-relax
OPT=-O -mcmodel=medany
ccFs:=main.cc init1.cc syscalls.cc
ASMs:=init.s
OBJ:=init.o init1.o main.o syscalls.o

# -nostdlib 	: is a 'ld' linker option; has no effect in 'cc' compiler
# -nostartfiles : is a 'ld' linker option; has no effect in 'cc' compiler
# -freestanding	: is a 'cc' option; has no effect in linker
# -lgcc			: includes multilib libraries; picks all necessary Math 'arthmetic libraries' for rv32i mul, div etc

# gcc calls linker 'ld' for linking - internal call

exe: $(OBJ)
	$(cc) -o $@ $^ $(LDFLAGS)

%.o: %.cc $(ccFs)
	$(cc) -c -o $@ $< $(OPT) $(CFLAGS)

%.o: %.s $(ASMs)
	$(cc) -c -o $@ $< $(CFLAGS)

strip_exe:
	$(strip) exe

exe.dump:
	$(objdump) -D exe > exe.dump

exe.bin:
	mkdir -p $(allSectionsDir)
	$(objcopy) -O binary --only-section=.text* --only-section=.rodata --only-section=.sdata2 --only-section=.data --only-section=.sdata --only-section=.sbss --only-section=.bss exe $(allSectionsDir)/exe.bin

	$(objcopy) -O binary --only-section=.text* exe $(allSectionsDir)/text
	$(objcopy) -O binary --only-section=.rodata exe $(allSectionsDir)/rodata
	$(objcopy) -O binary --only-section=.sdata2 exe $(allSectionsDir)/sdata2
	$(objcopy) -O binary --only-section=.data exe $(allSectionsDir)/data
	$(objcopy) -O binary --only-section=.sdata exe $(allSectionsDir)/sdata
	$(objcopy) -O binary --only-section=.sbss exe $(allSectionsDir)/sbss
	$(objcopy) -O binary --only-section=.bss exe $(allSectionsDir)/bss

exe.dat:
	hexdump -v -e '"%08x\n"' $(allSectionsDir)/exe.bin > $(allSectionsDir)/exe.dat
	cp $(allSectionsDir)/exe.dat .
	hexdump -v -e '"%08x\n"' $(allSectionsDir)/text > $(allSectionsDir)/text.dat
	hexdump -v -e '"%08x\n"' $(allSectionsDir)/rodata > $(allSectionsDir)/rodata.dat
	hexdump -v -e '"%08x\n"' $(allSectionsDir)/sdata2 > $(allSectionsDir)/sdata2.dat
	hexdump -v -e '"%08x\n"' $(allSectionsDir)/data > $(allSectionsDir)/data.dat
	hexdump -v -e '"%08x\n"' $(allSectionsDir)/sdata > $(allSectionsDir)/sdata.dat
	hexdump -v -e '"%08x\n"' $(allSectionsDir)/sbss > $(allSectionsDir)/sbss.dat
	hexdump -v -e '"%08x\n"' $(allSectionsDir)/bss > $(allSectionsDir)/bss.dat

disassembly.dump:
	sed 's/^/.word 0x/' exe.dat > disassembly.s
	$(cc) -c disassembly.s -o disassembly.o
	$(objdump) -d disassembly.o > disassembly.dump


all: exe strip_exe exe.dump exe.bin exe.dat disassembly.dump

clean:
	rm -rf *.o exe exe.* $(allSectionsDir) disassembly.*
