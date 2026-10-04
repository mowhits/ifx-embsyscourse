/* 
    You are writing software for a MCU with 3 memory components.

    Flash begins at 0x00 and is 32 KB
    SRAM1 begins at 0x20000000 and is 16 KB
    SRAM2 begins at 0x30000000 and is 8 KB
    Write a simple linker script for this MCU by referring to the linker script taught in the class today.
    Assign constant data and your code to the flash, Data and BSS to SRAM1
    Assume that your project contains a lot of C files and many of them intend to have one of their C functions assigned to .init input section and this must be accessed by CPU from SRAM2.
    Extend the Add.c you created above by adding a MAC_Init function which receives and returns nothing. Its only job is to initialize the global variable you defined in the C file to a negative fraction.
    Find out syntax for instructing the compiler to place this MAC_Init function in a .init section.
    From your main() in main.c, call the MAC_Init and MAC computing functions.
    Generate the ELF as taught in the class.
    Dump the header information of this ELF using the cross-compiled objdump tool and list the sections you see in the output.

    */
__FLASH_START = 0x00;
__FLASH_SIZE = 32K;

__SRAM1_START = 0x20000000;
__SRAM1_SIZE = 16K;

__SRAM2_START = 0x30000000;
__SRAM2_SIZE = 8K;

MEMORY {
    FLASH (rx) : ORIGIN = __FLASH_START, LENGTH = __FLASH_SIZE
    SRAM1 (rwx): ORIGIN = __SRAM1_START, LENGTH = __SRAM1_SIZE
    SRAM2 (rwx): ORIGIN = __SRAM2_START, LENGTH = __SRAM2_SIZE
}

SECTIONS {
    .text : {*(.text*)} > FLASH
    .rodata : {*(.rodata*)} > FLASH
    .data : {*(.data*)} > SRAM1 AT> FLASH
}
