MEMORY
{
    FLASH (rx) : ORIGIN = 0x8000000, LENGTH = 128K
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

ENTRY(isr_reset)

SECTIONS
{   
    .isr_vector : {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } > FLASH
    
    .text : {
        _start_text = .;

        *(.text)
        *(.text*)

        . = ALIGN(4);
        _end_text = .;
    } > FLASH

    .rodata : 
    {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
    } > FLASH

    _stored_data = .;

    .data : AT(_stored_data) {
        _start_data = .;
        *(.data)
        *(.data*)

        . = ALIGN(4);
        _end_data = .;
    } > RAM

    . = ALIGN(4);

    .bss : {
        _start_bss = .;

        *(.bss)
        *(.bss*)
        *(COMMON)

        . = ALIGN(4);
        _end_bss = .;
    }
}

_end_stack = ORIGIN(RAM) + LENGTH(RAM);