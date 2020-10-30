// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
/* A tailor made custom C library which supports minimal 
functionality for the user-level bare-metal program */

#ifndef MYCLIB
#define MYCLIB
#define FLOATING_POINT
#include <stdarg.h>
// write_char writes a char to location "__console_addr" defined in linker
extern unsigned int _stext[], _etext[];             // text section start and end address
extern unsigned int _svector[], _evector[];         // vector section start and end address
extern unsigned int _srodata[], _erodata[];         // rodata section start and end address
extern unsigned int _sdata[], _edata[];             // data section start and end address
extern unsigned int _ssdata[], _esdata[];           // data section start and end address
extern unsigned int _ssbss[], _esbss[];             // data section start and end address
extern unsigned int _sbss[], _ebss[];               // .bss section start and end address

extern unsigned int __sp[];                         // start of stack pointer
extern unsigned int __console_addr[];               // output console address

unsigned int write_char(char ch);            // write_char - writes a char to the console; returns 1 if write is successful else 0
unsigned int write_string(char* ch);         // write_string - writes string to the console; returns 1 if write is successful else 0

/********************************************************************************/

// itoa - radix "base10 - 10; base16 - 16 etc", uppercase "1 for A, 0 for a(incase of hex-base16)"
// zero_pad "number of zeros to be padded with the result"
// returns length of the buffer string
unsigned int itoa   (  
    int value, unsigned int radix, 
    unsigned int uppercase, unsigned int unsig,
    char *buffer, unsigned int zero_pad
);

#ifdef FLOATING_POINT
int ftoi (float f, int &in, int &fr);
int ftoi_print(float f);
#endif

/********************************************************************************/

int _putc(int ch, volatile int* print_addr);                    // _putc - puts a char in print_addr; always returns 1
int _puts(char *s, unsigned int len, volatile int* print_addr); // _puts - puts string in print_Addr; always returns 1
unsigned int _strlen(const char *s);                            // _strlen - returns the length of a const string

/********************************************************************************/

int printf_impl(volatile int* print_addr, const char *fmt, va_list va); // printf_impl - contains printf implementation
int addr_printf(volatile int* print_addr, const char *fmt, ...);        // addr_printf - printd to the given print_addr
int _printf (const char *fmt, ...);                                     // _printf - printd to the given __console_addr


#endif
