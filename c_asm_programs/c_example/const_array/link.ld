/*
 * Author: Tarun Govind Kesavamurthi
 * School: North Carolina State University
 * mail  : tkesava@ncsu.edu
 */

/* stack grows from bottom to top - keep in mind */

/*ENTRY(.text_init)*/

__sp = 0x0FFF0;

SECTIONS
{
    .text.init : {
        *(.text.init)
    }

    .text : {
        *(.text)
    }

    .rodata : {
    	*(.rodata)
    	*(.rodata.*)
    }

    .data : {
        *(.vector_section)
        *(.sbss)
        *(COMMON)
        *(.bss)
        *(.sdata)
        *(.data*)
        *(.got*)
    }
}
