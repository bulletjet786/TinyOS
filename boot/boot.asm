[bits 32]
MULTIBOOT_HEADER_MAGIC equ 0x1BADB002
MULTIBOOT_PAGE_ALIGN equ (1 << 0)
MULTIBOOT_MEM_INFO equ (1 << 1)
MULTIBOOT_HEADER_FLAGS equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEM_INFO
MULTIBOOT_CHECKSUM equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

[section .text]
        dd MULTIBOOT_HEADER_MAGIC
        dd MULTIBOOT_HEADER_FLAGS
        dd MULTIBOOT_CHECKSUM

[global start]
[global glb_multiboot_ptr]
[extern kernel_entry]

    start:
        cli

        mov esp, STACK_TOP
        mov ebp, 0x00
        and esp, 0x0FFFFFFF0
        mov [glb_multiboot_ptr], ebx
        mov al, 'H'
        mov [0xB8000], al
        mov al, (0 << 4) | (15 & 0x0F)
        mov [0xB8001], al
        call kernel_entry

    display_str

    stop:
        hlt
        jmp stop

[section .bss]
    stack:
        resb 32768
    glb_multiboot_ptr:
        resb 4

STACK_TOP equ $ - stack - 1