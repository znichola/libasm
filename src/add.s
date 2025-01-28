BITS 64

    global addOne, retZero

section .text
addOne:
    push rbp     ; save stack pointer
    mov rbp, rsp ; set the new stack "base pointer"

    ;mov DWORD PTR [rbp-4], eax ; move input value to stack, "base poitner"-4
    mov rax, rdi
    add rax, 1
    ;xor eax, eax
    ;mov eax, 12 

    pop rbp ; restore the stack pointer
    ret

retZero:
    mov eax, 42
    ret
