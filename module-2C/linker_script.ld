MEMORY {
    FLASH (rx) : ORIGIN = 0x00, LENGTH = 32K
    SRAM1 (rwx) : ORIGIN = 0x20000000, LENGTH = 16K
    SRAM2 (rwx) : ORIGIN = 0x30000000, LENGTH = 8K
}

SECTIONS {
    .text : {
        *(.text*)
        . = ALIGN(4);
    } > FLASH
    .rodata : {
        *(.rodata*)
        . = ALIGN(4);
    } > FLASH
    .data : {
        *(.data*)
        . = ALIGN(4);
    } > SRAM1 AT> FLASH
    .bss : {
        *(.bss*)
        . = ALIGN(4);
    } > SRAM1
    .init : {
        *(.init*)
    } > SRAM2 AT> FLASH
}
