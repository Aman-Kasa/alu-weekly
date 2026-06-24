; hello.asm
section .data
    msg db 'Hello, World!', 0xA  ; The string to print, 0xA is a newline
    len equ $ - msg              ; Calculate the length of the string

section .text
    global _start                ; Must be declared for the linker

_start:
    ; System Call: sys_write (4)
    mov eax, 4                   ; syscall number for write
    mov ebx, 1                   ; file descriptor 1 is stdout
    mov ecx, msg                 ; pointer to the message
    mov edx, len                 ; message length
    int 0x80                     ; call the kernel

    ; System Call: sys_exit (1)
    mov eax, 1                   ; syscall number for exit
    mov ebx, 0                   ; return code 0
    int 0x80                     ; call the kernel
