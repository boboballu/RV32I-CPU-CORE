// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// accessing variable defined in linker
//https://stackoverflow.com/questions/48561217/how-to-get-value-of-variable-defined-in-ld-linker-script-from-c
#include "myClib.h"

int main()
{
    int a = 10;
    _printf("Hello World :) => %08x", a);
    return 0;
}
