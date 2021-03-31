/*
    GNU linker script for STM32H750
*/

/* Specify the memory areas */
MEMORY
{
    FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 128K
    FLASH_ISR (rx)  : ORIGIN = 0x90000000, LENGTH = 64K    /* ITCMRAM 64K */
    FLASH_TEXT (rx) : ORIGIN = 0x90040000, LENGTH = 8M  

    DTCMRAM (xrw)     : ORIGIN = 0x20000000, LENGTH = 128K
    RAM (xrw)      : ORIGIN = 0x24000000, LENGTH = 512K
    RAM_D2 (xrw)      : ORIGIN = 0x30000000, LENGTH = 288K
    RAM_D3 (xrw)      : ORIGIN = 0x38000000, LENGTH = 64K
    ITCMRAM (xrw)     : ORIGIN = 0x00000000, LENGTH = 64K
    QSPIFLASH (rx)    : ORIGIN = 0x90000000, LENGTH = 8M
}

/* produce a link error if there is not this amount of RAM for these sections */
_minimum_stack_size = 2K;
_minimum_heap_size = 16K;

/* Define the stack.  The stack is full descending so begins just above last byte
   of RAM.  Note that EABI requires the stack to be 8-byte aligned for a call. */
_estack = ORIGIN(RAM) + LENGTH(RAM) - _estack_reserve;
_sstack = _estack - 16K; /* tunable */

/* RAM extents for the garbage collector */
_ram_start = ORIGIN(RAM);
_ram_end = ORIGIN(RAM) + LENGTH(RAM);
_heap_start = _ebss; /* heap starts just after statically allocated memory */
_heap_end = _sstack;

