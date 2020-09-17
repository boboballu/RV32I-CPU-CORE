// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// accessing variable defined in linker
//https://stackoverflow.com/questions/48561217/how-to-get-value-of-variable-defined-in-ld-linker-script-from-c
#include "myClib.h"

int main()
{
	char a[30] = "Hello World ;) \n";
	write_string(a);
	char number[10];
	itoa((int)(__sp), 10, 0, 0, number, 0);
	write_string(number);
	return 0;
}
