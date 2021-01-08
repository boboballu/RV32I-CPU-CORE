# Linking binaries with newlib (lsdc++)
**Author: Tarun Govind Kesavamurthi**
## cxxdemo -> This is the golden reference - ported example from picorv32 - scripts - cxxdemo example

The **xpack riscv tool-chain** come with a version of the newlib C standard library.

**common/riscv.ld** is used for linking binaries against the newlib library. Using this linker script will create a binary that has its entry point at 0x10000. (The default linker script does not have a static entry point, thus a proper ELF loader would be needed that can determine the entry point at runtime while loading the program.)

**common/syscall.c:** Newlib comes with a few syscall stubs. common/syscalls.c provides the basic implementation of the syscalls like **_exit, _write, _read, _sbrk etc**, overwriting the default stubs from newlib.

*Other important files*
 - "makevars.mk"            Additional .cc, .c and .S files

*Important IO parameters*
"params_header.h"               File is common to syscalls.c and start.S; Contains all parameters
In "params_header.h"
    - "__ram_size"              Ram size (4*1024*1024 ==  4MB)
    - "__start_stack"           Ram size - stack starts from bottom and grows towards the top of Ram
    - "__console_addr"          Output console address - ((4*1024*1024) + 4)
    - "__stop_addr"             Writing 1 to this memory address stops tb execution ((4*1024*1024) + 8)
