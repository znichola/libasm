#include <stdio.h>

int addOne(int a);
void doNothing();
int retZero();

int main() {
    int this = 0;
     this = addOne(2);
    doNothing();
    printf("the value: %d\nand zero: %d\n", this, retZero());
    return 0;
}
