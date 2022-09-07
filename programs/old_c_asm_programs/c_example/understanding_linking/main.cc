/*
riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -O3 -nostdlib test1.c -o test1
*/
void mem_write (unsigned int addr, int value) 
{
    asm("sw %0, 0(%1)": :"r"(value), "r"(addr));    
}
int main()
{
    const char a[4] = "abc";
    mem_write (84, (int)(a));   
}
