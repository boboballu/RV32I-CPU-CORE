// An extremely minimalist syscalls.c for newlib
// Based on riscv newlib libgloss/riscv/sys_*.c
// Inspired from Clifford Wolf's picorv32 project.
// modified by Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu

#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

// defined in start.S
// extern unsigned int __ram_size[];
// extern unsigned int __console_addr[];
// extern unsigned int __stop_addr[];
#include "params_header.h"

// #define __console_addr    (__ram_size + 4)    //((4*1024*1024) + 4)
// #define __stop_addr        (__ram_size + 8)    //((4*1024*1024) + 8)

#define __stop_execution() \
    *(volatile int*)__stop_addr = 1;


#define UNIMPL_FUNC(_f) ".globl " #_f "\n.type " #_f ", @function\n" #_f ":\n"

asm (
    ".text\n"
    ".align 2\n"
    UNIMPL_FUNC(_open)
    UNIMPL_FUNC(_openat)
    UNIMPL_FUNC(_lseek)
    UNIMPL_FUNC(_stat)
    UNIMPL_FUNC(_lstat)
    UNIMPL_FUNC(_fstatat)
    UNIMPL_FUNC(_isatty)
    UNIMPL_FUNC(_access)
    UNIMPL_FUNC(_faccessat)
    UNIMPL_FUNC(_link)
    UNIMPL_FUNC(_unlink)
    UNIMPL_FUNC(_execve)
    UNIMPL_FUNC(_getpid)
    UNIMPL_FUNC(_fork)
    UNIMPL_FUNC(_kill)
    UNIMPL_FUNC(_wait)
    UNIMPL_FUNC(_times)
    UNIMPL_FUNC(_gettimeofday)
    UNIMPL_FUNC(_ftime)
    UNIMPL_FUNC(_utime)
    UNIMPL_FUNC(_chown)
    UNIMPL_FUNC(_chmod)
    UNIMPL_FUNC(_chdir)
    UNIMPL_FUNC(_getcwd)
    UNIMPL_FUNC(_sysconf)
    "j unimplemented_syscall\n"
);

void unimplemented_syscall()
{
    const char *p = "Unimplemented system call called!\n";
    while (*p)
        *(volatile int*)__console_addr = *(p++);
        __stop_execution();
        __builtin_unreachable();
}

ssize_t _read(int file, void *ptr, size_t len)
{
    // always EOF
    return 0;
}

ssize_t _write(int file, const void *ptr, size_t len)
{
    const void *eptr = ptr + len;
    while (ptr != eptr)
        *(volatile int*)__console_addr = (int) *(char*)(ptr++);
    return len;
}

int _close(int file)
{
    // close is called before _exit()
    return 0;
}

int _fstat(int file, struct stat *st)
{
    // fstat is called during libc startup
    errno = ENOENT;
    return -1;
}

void *_sbrk(ptrdiff_t incr)
{
    extern unsigned char _end[];   // Defined by linker
    static unsigned long heap_end;

    if (heap_end == 0)
        heap_end = (long)_end;

    heap_end += incr;
    return (void *)(heap_end - incr);
}

void _exit(int exit_status)
{
    __stop_execution();
    __builtin_unreachable();
}