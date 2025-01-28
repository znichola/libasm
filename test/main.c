#include <stdio.h>

int addOne(int a);
int retZero();

int main() {
    printf("the value: %d\nand zero: %d\n", 
            addOne(68), retZero()
           );
    return 0;
}
