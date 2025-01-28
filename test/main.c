#include <stdio.h>

int addOne(int a);
int retZero();
size_t ft_strlen(char *s);

int main() {
    printf("the value: %d\nand zero: %d\nand strlen %zu\n", 
            addOne(68), retZero(), ft_strlen("hello world")
           );
    return 0;
}
