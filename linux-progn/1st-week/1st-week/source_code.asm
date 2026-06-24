section .data
    msg db 'Hello, Assembly World!', 0xA
    msg_len equ $ - msg

section .text
    global _start

_start:
    ; Write message to stdout
    mov eax, 4          ; sys_write
    mov ebx, 1          ; file descriptor (stdout)
    mov ecx, msg        ; pointer to message
    mov edx, msg_len    ; length of message
    int 0x80            ; interrupt kernel call

    ; Exit process
    mov eax, 1          ; sys_exit
    mov ebx, 0          ; exit code 0
    int 0x80            ; interrupt kernel call

