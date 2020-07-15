// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
#include <stdint.h>

// init source file in C
// this file contains the .text_init section, which calls main
// vector table for IO's, section pointers etc
// A reset handler
#define STACK_START 0x0FFF0
int main(); // main definition
void text_init (void) __attribute__((section(".text_init"), optimize(0)));
void end_program (void) __attribute__((section(".text_init"), optimize(0)));

uint32_t vector [] __attribute__((section(".vector_section"))) = {
    STACK_START,
    (uint32_t) text_init,
    (uint32_t) &end_program
};

void text_init () {
    //set up the stack pointer, using a constant defined in the linker script.
    asm("la sp, %0": : "i"(STACK_START-32)); 
    // call main and exit once main returns
    main();
    end_program();
}
void end_program () {
    // wait forever
    while(1);
}