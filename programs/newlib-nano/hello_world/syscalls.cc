#include <sys/stat.h>
#include <sys/types.h>
// write_char writes a char to location "__console_addr" defined in linker
extern unsigned int __sp[];                         // start of stack pointer
extern unsigned int __console_addr[];               // output console address
extern unsigned int __stop_addr[];

/* Register name faking - works in collusion with the linker.  */
register char * stack_ptr asm ("sp");

int _close(int file) { return -1; }
 
int _fstat(int file, struct stat *st) {
    st->st_mode = S_IFCHR;
    return 0;
}
 
int _isatty(int file) { return 1; }
 
int _lseek(int file, int ptr, int dir) { return 0; }
 
int _open(const char *name, int flags, int mode) { return -1; }
 
int _read(int file, char *ptr, int len) {
    int todo;
    // if(len == 0)
    // return 0;
    // while(UART_FR(UART0_ADDR) & UART_FR_RXFE);
    // *ptr++ = UART_DR(UART0_ADDR);
    // for(todo = 1; todo < len; todo++) {
    //     if(UART_FR(UART0_ADDR) & UART_FR_RXFE) {
    //         break;
    //     }
    //     *ptr++ = UART_DR(UART0_ADDR);
    // }
    return todo;
}
 
char *heap_end = 0;

caddr_t _sbrk(int incr) {
    extern char   end asm ("_end");	/* Defined by the linker.  */
    static char * heap_end;
    char *        prev_heap_end;

    if (heap_end == 0)
        heap_end = &end;
  
    prev_heap_end = heap_end;
  
    if (heap_end + incr > stack_ptr) {
        return (caddr_t) -1;
    }

    heap_end += incr;
    return (caddr_t) prev_heap_end;
}
 
int _write(int file, char *ptr, int len) {
    int todo;
    volatile int* tx = (volatile int*) (int)__console_addr;
    for (todo = 0; todo < len; todo++) {
        *tx = (int)ptr[todo];
    }
    return len;
}