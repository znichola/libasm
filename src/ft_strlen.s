BITS 64

    global ft_strlen

section .text
ft_strlen:
    push rbp     ; save the stack pointer
    mov rbp, rsp ; set the new stack "base poitner"

    ; rdi rsi are first and second args
    ; rax/eax is return value
    ; rcx is the counter
    ; rdx is the scratch data

    ; bits 64  32  16 8  8
    ;      rax eax ax ah al

    mov rax, 0        ; set i to 0, it's also the return "rax"
    cmp BYTE [rdi], 0 ; compare and set flag
    je .ret           ; if equal jump
.loop:
    add rax, 1             ; i = i + 1
    cmp BYTE [rdi+rax], 0  ; use stored i value to adjust the memory location being looked at
    jne .loop              ; jump if not zero, cmp sets the EFLAGS register which is checked
.ret:

    pop rbp ; function cleanup, but it's not requiered?
    ret
