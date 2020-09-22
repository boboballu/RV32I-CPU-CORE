// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// accessing variable defined in linker
//https://stackoverflow.com/questions/48561217/how-to-get-value-of-variable-defined-in-ld-linker-script-from-c
#include "myClib.h"

unsigned int write_chari (int ch) {
	int ret = 0;
	volatile int* tx = (volatile int*) __console_addr;
	*tx = ch;
	if (*tx == ch)
		ret = 1;
	else
		ret = 0;
	return ret;
}

int main()
{
	char a[30] = "Hello World ;) \n";
	// write_string(a);
	int i=0;
	while (a[i] != '\0') {
		write_chari((int)a[i]);
		i++;
	}

	// char number[10];
	// itoa((int)(__sp), 10, 0, 0, number, 0);
	// write_string(number);
	return 0;
}
