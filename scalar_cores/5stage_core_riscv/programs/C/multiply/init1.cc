// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
#include <stdint.h>
#include "myClib.h"

// init source file in C
// this file contains the .textinit section, which calls main,
// vector table for IO's, section pointers etc
// A reset handler
int main(); // main definition

// extern "C" is mandatory to make this function callable in assembly
// https://embeddedartistry.com/blog/2017/05/01/mixing-c-and-c-extern-c/
// The above site talks abt transitioning from C and C++; But it's same for C or C++ to Asm
extern "C" void textinit () __attribute__((section(".init.text0"), optimize(0)));

uint32_t vector [] __attribute__((section(".vector_section"))) = {
    (uint32_t) __sp,
    (uint32_t) &textinit,
};

void textinit (void) {
    // reinitialize stack pointer if necessary; using a constant defined in the linker script.
    // asm("la sp, %0": : "i"(STACK_START-32));
    // call main and exit once main returns
    main();
}
