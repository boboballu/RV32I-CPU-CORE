/*
riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -O3 -nostdlib test1.c -o test1
*/
void mem_write (unsigned int addr, int value) 
{
	asm("sw %0, 0(%1)": :"r"(value), "r"(addr));	
}
int main()
{
//    volatile char* tx = (volatile char*) 4000;
    char hello[20] = "Hello";
    
    int i = 0;
    while (hello[i] != '\0') {
  //      *tx = hello[i];
	mem_write(4000, hello[i]);
        i++;
    }
}
