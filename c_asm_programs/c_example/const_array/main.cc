/*
riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -O3 -nostdlib test1.c -o test1
*/
int main()
{
	volatile char* tx = (volatile char*) 4000;
	char a[6] = "hello";
	
	int i=0;
	while (i < 5) {
		*tx = a[i];
		i++;
		tx++;
	}   
}
