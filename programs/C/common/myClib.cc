// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
/* A tailor made custom C library which supports minimal 
functionality for the user-level bare-metal program */
#include <stdint.h>
#include "myClib.h"
/********************************************************************************/

// write_char - writes a char to the console; returns 1 if write is successful else 0
unsigned int write_char(char ch) {
    volatile int* tx = (volatile int*) (int)__console_addr;
    *tx = (int)ch;
    return 0;
}
/********************************************************************************/

// write_string - writes string to the console; returns 1 if write is successful else 0
unsigned int write_string(char* ch) {
    int i = 0;
    int ret = 1;
    while (ch[i] != '\0') {
        ret &= write_char(ch[i]);
        i++;
    }
    ret &= write_char('\0');
    return ret;
}
/********************************************************************************/

// _putc - puts a char in print_addr; always returns 1
int _putc(int ch, volatile int* print_addr) {
    *print_addr = (int) ch;
    // *print_addr = (int) '\0';
    return 1;
}
/********************************************************************************/

// _puts - puts string in print_Addr; always returns 1
int _puts(char *s, unsigned int len, volatile int* print_addr)
{
    unsigned int i;

    /* Copy to buffer */
    for (i = 0; i < len; i++)
        *print_addr = (int) s[i];
    *print_addr = (int) '\0';

    return 1;
}
/********************************************************************************/

// _strlen - returns the length of a const string
unsigned int _strlen(const char *s) {
    unsigned int len = 0;
    while (s[len] != '\0') len++;
    return len;
}
/********************************************************************************/

// itoa - radix "base10 - 10; base16 - 16 etc", uppercase "1 for A, 0 for a(incase of hex-base16)"
// zero_pad "number of zeros to be padded with the result"
// returns length of the buffer string
unsigned int itoa(
    int value, unsigned int radix, 
    unsigned int uppercase, unsigned int unsig,
    char *buffer, unsigned int zero_pad
)
{
    char    *pbuffer = buffer;
    int    negative = 0;
    unsigned int    i, len;

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

/********************************************************************************/
#ifdef FLOATING_POINT
// ftoi - input float value; output in and fr 
int ftoi (float f, int &in, int &fr) { 
    in = (int) f;
    float fraction=0;
    fraction = f - in;
    fraction = (fraction > 0) ? fraction : -fraction;
    fr = (int) (fraction * 100000000);
    in = (int) (f - fraction);
    return 0;
}


int ftoi_print(float f) {
    int in, fr;
    ftoi(f, in, fr);
    char in_c[10], fr_c[10];
    // _printf("%d.%d", in, fr);
    itoa(in, 10, 0, 0, in_c, 0);
    itoa(fr, 10, 0, 0, fr_c, 0);
    write_string(in_c); write_char('.'); write_string(fr_c);
    return 0;
}
#endif

/********************************************************************************/
// printf_impl - contains printf implementation
int printf_impl(volatile int* print_addr, const char *fmt, va_list va) {
    char bf[24];
    char ch;

    while ((ch=*(fmt++))) {
        if (ch!='%')
            _putc(ch, print_addr);
        else {
            char zero_pad = 0;
            char *ptr;
            unsigned int len;
            int in, fr;

            ch=*(fmt++);

            /* Zero padding requested */
            if (ch=='0') {
                ch=*(fmt++);
                if (ch == '\0')
                    goto end;
                if (ch >= '0' && ch <= '9')
                    zero_pad = ch - '0';
                ch=*(fmt++);
            }

            switch (ch) {
                case 0:
                    goto end;

                case 'u':
                case 'd':
                    len = itoa(va_arg(va, unsigned int), 10, 0, (ch=='u'), bf, zero_pad);
                    _puts(bf, len, print_addr);
                    break;

                case 'x':
                case 'X':
                    len = itoa(va_arg(va, unsigned int), 16, (ch=='X'), 1, bf, zero_pad);
                    _puts(bf, len, print_addr);
                    break;

                case 'c' :
                    _putc((char)(va_arg(va, int)), print_addr);
                    break;

                case 's' :
                    ptr = va_arg(va, char*);
                    _puts(ptr, _strlen(ptr), print_addr);
                    break;
                
                #ifdef FLOATING_POINT
                case 'f' :
                    ftoi_print((float)(va_arg(va, double)));
                    break;
                #endif
                
                default:
                    _putc(ch, print_addr);
                    break;
            }
        }
    }
end:
    return 0;
}

/********************************************************************************/
// addr_printf - printd to the given print_addr
int addr_printf(volatile int* print_addr, const char *fmt, ...) {
    int ret;
    va_list va;
    va_start(va, fmt);
    ret = printf_impl(print_addr, fmt, va);
    va_end(va);

    return ret;
}

/********************************************************************************/
// _printf - printd to the given __console_addr
int _printf (const char *fmt, ...) {
    int ret;
    va_list va;
    va_start(va, fmt);
    ret = printf_impl((volatile int*) __console_addr, fmt, va);
    va_end(va);

    return ret;
}