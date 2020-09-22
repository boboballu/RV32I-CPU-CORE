//Author: Tarun Govind Kesavamurthi
//School: North Carolina State University
//mail  : tkesava@ncsu.edu

int myfunction(int x, int y)
{
	return x+y;
}

void mem_write (unsigned int addr, int value) 
{
	asm("sw %0, 0(%1)": :"r"(value), "r"(addr));	
}
int main(void)
{
	// declare some variables
	int x=12, y=34, z;

	z = myfunction(x,y);
//	debug_print(z);
	mem_write(84, z);
	return z;
}
