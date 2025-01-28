#include <stdio.h>

extern int addOne(int a);

int main() {
    int this = addOne(2);
    printf("the value: %d\n", this);
    return 0;
}
