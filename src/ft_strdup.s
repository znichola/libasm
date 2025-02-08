BITS 64

extern malloc

global ft_strdup

ft_strdup:
    push rbp
    push rbx ; save callee saved register
    mov rbp, rsp

    ; rdi rsi are first and second args
    ; rax/eax is return value
    ; rcx is the counter
    ; rdx is the scratch data

    ; bits 64  32  16 8  8
    ;      rax eax ax ah al

    mov rbx, rdi ; store string ptr in rbx
    mov rdi, 0 ; i = 0 string length
    cmp BYTE [rbx], 0
    je .end_strlen
.loop_strlen:
    add rdi, 1
    cmp BYTE [rbx+rdi], 0
    jne .loop_strlen
.end_strlen:
    add rdi, 1
    mov rax, 0
    call malloc wrt ..plt ; wrt ..plt for the linker and shared lib
                          ; https://www.nasm.us/xdoc/2.11.08/html/nasmdoc7.html#section-7.9.3
                          ; allocated mem is already in rax

    test rax, rax
    je .malloc_failed ; rax == NULL

    ; do the copy
    movzx rdx, BYTE [rbx] ; copy byte to comparison register zero extend it
    mov rcx, 0 ; i = 0
    test dl, dl ; check src[0] != 0
    je .ret_strcpy
.loop_strcpy:
    mov BYTE [rax+rcx], dl ; d[i] = s[i]
    add rcx, 1             ; i += 1
    movzx rdx, BYTE [rbx+rcx] ; copy and zero extend next char for comparison
    test dl, dl ; s[i] != 0
    jne .loop_strcpy
.ret_strcpy:
    mov BYTE [rax+rcx], 0 ; d[i] = 0

.malloc_failed:
    pop rbx
    pop rbp
    ret

