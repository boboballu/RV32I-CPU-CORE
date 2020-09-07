// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// accessing variable defined in linker 
//https://stackoverflow.com/questions/48561217/how-to-get-value-of-variable-defined-in-ld-linker-script-from-c
extern unsigned int __sp[];

//char write_char (int c); // __attribute__((optimize(0)));
/*volatile*/ 

char write_char(int c)  {
	int ret = 0;	
	volatile int* tx = (volatile int*) 65532;
	*tx = c;
	if (*tx == c)
		ret = 1;
	else
		ret = 0;
	return ret;
}

static unsigned int
mini_itoa(int value, unsigned int radix, unsigned int uppercase, unsigned int unsig,
	 char *buffer, unsigned int zero_pad)
{
	char	*pbuffer = buffer;
	int	negative = 0;
	unsigned int	i, len;

	/* No support for unusual radixes. */
	if (radix > 16)
		return 0;

	if (value < 0 && !unsig) {
		negative = 1;
		value = -value;
	}

	/* This builds the string back to front ... */
	do {
		int digit = value % radix;
		*(pbuffer++) = (digit < 10 ? '0' + digit : (uppercase ? 'A' : 'a') + digit - 10);
		value /= radix;
	} while (value > 0);

	for (i = (pbuffer - buffer); i < zero_pad; i++)
		*(pbuffer++) = '0';

	if (negative)
		*(pbuffer++) = '-';

	*(pbuffer) = '\0';

	/* ... now we reverse it (could do it recursively but will
	 * conserve the stack space) */
	len = (pbuffer - buffer);
	for (i = 0; i < len / 2; i++) {
		char j = buffer[i];
		buffer[i] = buffer[len-i-1];
		buffer[len-i-1] = j;
	}

	return len;
}

int main()
{
	char a[30] = "Hello World ;) \n";
	
	int i=0;
	// while (a[i] != '\0') {
	// 	write_char((int)a[i]);
	// //	*tx = a[i];
	// 	i++;
	// //	tx = tx + 1;
	// }  
	//tx = tx+16;
	volatile int* tx_int = (volatile int*) 65532;
	char number[10];
	mini_itoa((int)(__sp), 10, 0, 0, number, 0);
	i = 0;
	while (number[i] != '\0') {
 		write_char((int)number[i]);
		 i++;
	}
	return 0;
}