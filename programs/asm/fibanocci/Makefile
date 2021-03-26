ASM = fibanocci.s

asmbl:
	riscv-none-embed-gcc -c -o start.elf $(ASM)
	riscv-none-embed-objcopy -O binary start.elf start.bin
	hexdump -v -e '"%08x\n"' start.bin > start32.hex

clean:
	rm -rf start.* start32.*
