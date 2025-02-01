BITS 64

    global ft_strcpy

section .text
ft_strcpy:
    push rbp
    mov rbp, rsp

    ; rdi rsi are first and second args
    ; rax/eax is return value
    ; rcx is the counter
    ; rdx is the scratch data

    ; bits 64  32  16 8  8
    ;      rax eax ax ah al

    mov rax, rdi ; move pointer for dest to return rax
    movzx rdx, BYTE [rsi] ; copy byte to comparison register zero extend it
    mov rcx, 0 ; i = 0
    test dl, dl ; check src [0] != 0
    je .ret
.loop:
    mov BYTE [rax+rcx], dl ; d[i] = s[i]
    add rcx, 1             ; i += 1
    movzx rdx, BYTE [rsi+rcx] ; copy and zero extend next char for comparison
    test dl, dl ; s[i] != 0
    jne .loop
.ret:
    mov BYTE [rax+rcx], 0 ; d[i] = 0
    pop rbp
    ret

