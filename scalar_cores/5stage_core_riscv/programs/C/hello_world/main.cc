// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// accessing variable defined in linker 
//https://stackoverflow.com/questions/48561217/how-to-get-value-of-variable-defined-in-ld-linker-script-from-c
extern unsigned int __sp[];

//char write_char (int c); // __attribute__((optimize(0)));
/*volatile*/ char write_char(int c)  {
	int ret = 0;	
	volatile int* tx = (volatile int*) 65532;
	
	*tx = c;
	
	if (*tx == c) {
		ret = 1;
	}
	else {
		ret = 0;
	}
	return ret;

//	return *tx;
}

int main()
{
	char a[30] = "Hello World ;) \n";
	
	int i=0;
	while (a[i] != '\0') {
		write_char((int)a[i]);
	//	*tx = a[i];
		i++;
	//	tx = tx + 1;
	}  
	//tx = tx+16;
	volatile int* tx_int = (volatile int*) 65532;
 	*tx_int = (unsigned int)__sp; 
}

