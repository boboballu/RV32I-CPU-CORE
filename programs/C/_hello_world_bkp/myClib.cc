// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
/* A tailor made custom C library which supports minimal 
functionality for the user-level bare-metal program */
#include <stdint.h>
#include "myClib.h"

// write_char - writes a char to the console; returns 1 if write is successful else 0
unsigned int write_char(char ch) {
    volatile int* tx = (volatile int*) (int)__console_addr;
    *tx = (int)ch;
    if (*tx == (int)ch)
        return 1;
    else
        return 0;
}

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