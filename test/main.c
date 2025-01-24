#include "stdio.h"
#include "unistd.h"
#include "string.h"

void expect(unsigned int res) {
   if (res) {
       printf("Test failed\n");
   } else {
       printf("Test passed\n");
   }
}

int main() {
    write(1, &"hellow world", 7);

    char *s[] = {
         "hello world"
         ,"these are not the droids you are looking for"
         ,""
         ,"\n\n\n"
    };

    for (int i = 0; i < 4; i++) {
        printf("%ld\n", strlen(s[i]));
    }

    return (1);
}
