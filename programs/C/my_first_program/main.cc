// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// accessing variable defined in linker 
//https://stackoverflow.com/questions/48561217/how-to-get-value-of-variable-defined-in-ld-linker-script-from-c
extern unsigned int __sp[];

char write_char(int c) {
    int ret = 0;    
    volatile int* tx = (volatile int*) 65532;
    *tx = c;
    
    // check if the optput memory is properly asserted
    if (*tx == c)
        ret = 1;
    else
        ret = 0;
    
    return ret;
}

// main function - called in init.s
int main(){
    char a[] = "This is the my first program ;) \n";
    int i=0;
    while (a[i] != '\0') {
        write_char((int)a[i]);
        i++;
    }  
    volatile int* tx_int = (volatile int*) 65532;
     *tx_int = (unsigned int)__sp; 
}
