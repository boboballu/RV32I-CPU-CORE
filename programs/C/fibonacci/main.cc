/*
riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -O3 -nostdlib test1.c -o test1
*/
int main()
{
    volatile int* tx = (volatile int*) 65540;

	int i, n = 12;
	int t1 = 0, t2 = 1, nextTerm;
	for (i = 1; i <= n; ++i) {
        	*tx = t1;
        	nextTerm = t1 + t2;
        	t1 = t2;
        	t2 = nextTerm;
    	}
}
