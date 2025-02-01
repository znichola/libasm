BITS 64

    global ft_strcmp

section .text
ft_strcmp:
    push rbp
    mov rbp, rsp

    ; rdi rsi are first and second args
    ; rax/eax is return value
    ; rcx is the counter
    ; rdx is the scratch data

    movsx eax, BYTE [rdi]
    test al, al ; != \0  test is a logical and
    je .mov_sub_ret

    mov rcx, 0
.loop:
    movsx eax, BYTE [rdi+rcx] ; load next char from s1
    movsx edx, BYTE [rsi+rcx] ; load next char from s2
    test al, al ; s1[i] != \0
    je .sub_ret ; return if s1 is zero

    add rcx, 1 ; i++
    sub eax, edx ; subtract the two characters
    cmp eax, 0 ; check res == 0
    je .loop ; if equal loop
    jne .ret ; else skip to return

.mov_sub_ret:
    movsx edx, BYTE [rsi]
.sub_ret:
    sub eax, edx
.ret:
    pop rbp
    ret

;    mov rax, 0
;    mov al, BYTE [rdi] ; al/dil is lower byte of rax/rdi
;    sub al, BYTE [rsi]
;    movsx eax, al
;    test al, al
;    jne .retnot
;    mov rcx, 1 ; some instruction use it as a counter
;.loop:
;    mov al, BYTE [rsi+rcx]
;    sub al, BYTE [rdi+rcx]
;    movsx eax, al
;    cmp eax, 0
;    inc rcx
;    je .loop
;.retnot:
;
