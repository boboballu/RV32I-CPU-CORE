// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
#include <stdint.h>

// init source file in C
// this file contains the .textinit section, which calls main
// vector table for IO's, section pointers etc
// A reset handler
#define STACK_START 0x0FFF0
int main(); // main definition
void textinit () __attribute__((section(".text.init0"), optimize(0)));
void endpgm (void) __attribute__((section(".text.init1"), optimize(0)));

uint32_t vector [] __attribute__((section(".vector_section"))) = {
    STACK_START,
    (uint32_t) textinit,
    (uint32_t) &endpgm
};

void textinit () {
    //set up the stack pointer, using a constant defined in the linker script.
    asm("la sp, %0": : "i"(STACK_START-32)); 
    // call main and exit once main returns
    main();
    endpgm();
}
void endpgm () {
    // wait forever
    while(1);
}