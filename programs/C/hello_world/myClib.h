// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
/* A tailor made custom C library which supports minimal 
functionality for the user-level bare-metal program */

#ifndef MYCLIB
#define MYCLIB
// write_char writes a char to location "__console_addr" defined in linker
extern unsigned int _stext[], _etext[];             // text section start and end address
extern unsigned int _svector[], _evector[];         // vector section start and end address
extern unsigned int _srodata[], _erodata[];         // rodata section start and end address
extern unsigned int _sdata[], _edata[];             // data section start and end address
extern unsigned int _sbss[], _ebss[];               // .bss section start and end address


extern unsigned int __sp[];                         // stack pointer
extern unsigned int __console_addr[];               // output console address

unsigned int write_char(char ch);            // write_char - writes a char to the console; returns 1 if write is successful else 0
unsigned int itoa   (  
    int value, unsigned int radix, 
    unsigned int uppercase, unsigned int unsig,
    char *buffer, unsigned int zero_pad
);
unsigned int write_string(char* ch);         // write_string - writes string to the console; returns 1 if write is successful else 0

#endif
