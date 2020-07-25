/*
 * Author: Tarun Govind Kesavamurthi
 * School: North Carolina State University
 * mail  : tkesava@ncsu.edu
 */
/********************************************************************************/

/* stack grows from bottom to top - keep in mind */

/* doesn't pick textinit function bit picks main surpricingly */
/* ENTRY(write_char) */

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
        *(.sbss)
        *(COMMON)
        *(.bss)
        *(.sdata)
        *(.data*)
        *(.got*)
    }
}
