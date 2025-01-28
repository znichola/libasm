BITS 64

    global addOne, doNothing, retZero
section .text
addOne:
    push rbp     ; save stack pointer
    mov rbp, rsp ; set the new stack "base pointer"

    ;mov DWORD PTR [rbp-4], eax ; move input value to stack, "base poitner"-4
    ; mov rdx, rdi

    add edx, 0x3

    pop rbp ; restore the stack pointer
    ret


doNothing:
    ret

retZero:
    mov eax, 42
    ret
