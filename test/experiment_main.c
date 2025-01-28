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

size_t ft_strlen(const char *s) {
    size_t i = 0;
    while(s[i] == '\0') {
        i++;
    }
    return i;
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
        expect(strlen(s[i]) == ft_strlen(s[i]));
    }

    return (1);
}
