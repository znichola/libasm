BITS 64

    global ft_write

section .text
ft_write:
    push rbp
    mov rbp, rsp

    ; rdi rsi are first and second args
    ; rax/eax is return value
    ; rcx is the counter
    ; rdx is the scratch data

    ; bits 64  32  16 8  8
    ;      rax eax ax ah al

    mov rax, 1 ; 1 is syscall for write
    ; arguments are the same as write()
    syscall

    pop rbp
    ret
