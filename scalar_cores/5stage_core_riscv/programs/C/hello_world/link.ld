/*
 * Author: Tarun Govind Kesavamurthi
 * School: North Carolina State University
 * mail  : tkesava@ncsu.edu
 */
/********************************************************************************/
/* reference : https://docs.rtems.org/releases/rtemsdoc-4.7.3/share/rtems/html/bsp_howto/bsp_howto00021.html */
/* stack grows from bottom to top - keep in mind */

/* doesn't pick textinit function bit picks main surpricingly */
/* ENTRY(write_char) */

__sp = 0x0FFF0;

SECTIONS
{
    .text.init : {
        *(.text.init0)
        *(.text.init1)
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
