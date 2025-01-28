# libasm

> :warn: Some assembly required

Project for 42Nice

## Registers

It's obvious and written everywhere, but these are the input registers for function arguments, dont get this wrong!

> rdi, rsi, rdx, rcx, r8, and r9

And the return register is also important

> rax

## Development

Usefull watch while writing assmebly
```
watch "make tst && ./tst"
```

Local gotbolt version
```
gcc test.c -c -S -o - -masm=intel | grep -vE '\s+\.'
```

## Links n stuff

- [nasm ref](https://www.cs.uaf.edu/2017/fall/cs301/reference/x86_64.html)
- [calling convetion](https://en.wikipedia.org/wiki/X86_calling_conventions)
- [compiler explorer](https://godbolt.org/)
- [linking asm to C](https://stackoverflow.com/questions/24991944/linking-c-with-nasm#answer-24992571)
- [linking with asm](https://wjwrobot.github.io/2020/01/28/Link-Static-Dynamic-Library-in-C-C-on-Linux/)
- [calling convetion x86_64](https://www.nasm.us/doc/nasmdo12.html)

