BITS 64

    extern __errno_location
    global ft_read

section .text
ft_read:
    push rbp
    mov rbp, rsp

    ; rdi rsi are first and second args
    ; rax/eax is return value
    ; rcx is the counter
    ; rdx is the scratch data

    ; bits 64  32  16 8  8
    ;      rax eax ax ah al

    mov rax, 0 ; syscall for read 
    ; argument order is same, so nothing is done
    syscall 

    cmp rax, 0
    jns .ret
    mov rdi, rax
    call __errno_location wrt ..plt
    neg rdi
    mov [rax], rdi
    mov rax, -1

.ret:
    pop rbp
    ret
