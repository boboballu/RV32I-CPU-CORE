/*
 * Author: Tarun Govind Kesavamurthi
 * School: North Carolina State University
 * mail  : tkesava@ncsu.edu
 */
/********************************************************************************/
/* reference : https://docs.rtems.org/releases/rtemsdoc-4.7.3/share/rtems/html/bsp_howto/bsp_howto00021.html */
/* stack grows from bottom to top - keep in mind */

/* doesn't pick textinit function but picks main surpricingly */

OUTPUT_ARCH( "riscv" )

/* ram is word addressable and 1 word is 4 bytes */
/* 64k bytes implies 16k words in ram */
MEMORY {
  ram      (rwx): ORIGIN = 0x00000000, LENGTH = 256k   
}

/* linker symbols goes here */
/* __sp = 0x0FFFF; */
__console_addr  = 0x40004;
__stop_addr     = 0x40008; 
/* ENTRY(_START) */

__sp = (ORIGIN(ram) + LENGTH(ram) - 4);
/* # Problem with linker is, it provides symbols in 4byte word boundary
# I am not sure whether this fact is correct, but ut sets stack to 65536!
# This overflows the stack, since my memory ranges only from 0 to 65535 */

SECTIONS
{
    .text (ORIGIN(ram)) : {
        PROVIDE(_stext = .);
        *(.init)
        *(.init.*)
        *(.text)
        /**(.text.*)*/
        PROVIDE(_etext = .);

        . = ALIGN(4);
        PROVIDE(_svector = .);
        *(.vector*)
        . = ALIGN(4);
        PROVIDE(_evector = .);
    
    } > ram

    .rodata : {
        . = ALIGN(4);
        PROVIDE(_srodata = .);
    	*(.rodata)
    	*(.rodata.*)
        . = ALIGN(4);
        PROVIDE(_erodata = .);
    } > ram

    .sdata2 : {
        *(.sdata2)
        *(.sdata2.*)
    } > ram

    .data : {
        . = ALIGN(4);
        PROVIDE(_sdata = .);
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        PROVIDE(_edata = .);
    } > ram

    /* riscv compiler a linker optimization called linker relaxation. hence as a part of it,
    There is are new sections introduced like .sdata, .srodata, .sbss etc*/
    .sdata : {
        __global_pointer$ = . + 0x800;
        *(.srodata.cst16) *(.srodata.cst8) *(.srodata.cst4) *(.srodata.cst2) *(.srodata .srodata.*)
        *(.sdata .sdata.* .gnu.linkonce.s.*)
    } > ram

    .sbss : {
        *(.dynsbss)
        *(.sbss .sbss.* .gnu.linkonce.sb.*)
        *(.scommon)
    } > ram

    .bss : {
        *(.bss)
        *(.bss.*)
    } > ram
    _end = .;
    end = .;
}
