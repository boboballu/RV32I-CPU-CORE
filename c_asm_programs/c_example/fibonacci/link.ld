/*
 * Author: Tarun Govind Kesavamurthi
 * School: North Carolina State University
 * mail  : tkesava@ncsu.edu
 */

/* stack grows from bottom to top - keep in mind */

__sp = 0x10000;

SECTIONS
{
    .text.init : {
        *(.text.init)
    }

    .text : {
        *(.text)
    }

    .data : {
        *(.sbss)
        *(COMMON)
        *(.bss)
        *(.sdata)
        *(.rodata)
        *(.data*)
        *(.got*)
    }
}
