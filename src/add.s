BITS 64

global addOne;

section .data

section .text

addOne:
    ;push rbp     ; save stack pointer
    ;mov rbp, rsp ; set the new stack "base pointer"

    ;mov DWORD PTR [rbp-4], eax ; move input value to stack, "base poitner"-4
    ; mov rdx, rdi

    ;add rdx, 3
    mov rdx, 1
    ret
    ;pop rbp ; restor the stack pointer
    ;ret

