#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "libasm.h"

void expect(bool res);

void test_strlen();
void test_strcmp();

int main() {
    test_strlen();
    test_strcmp();
    
    return 0;
}

void test_strlen() {
    char *s[] = {
         "hello world"
         ,"these are not the droids you are looking for"
         ,""
         ,"\n\n\n"
    };

    printf("Testing strlen\n");

    for (int i = 0; i < 4; i++) {
        bool res = strlen(s[i]) == ft_strlen(s[i]);
        expect(res);
        if (!res)
            printf("\
      expected len: %ld\n\
      received len: %ld\n\
      for string  : \"%s\"\n\
", strlen(s[i]), ft_strlen(s[i]), s[i]);
    }

    return;
}

int gelt(int i) {
    if (i > 0) return 1;
    if (i == 0) return 0;
    return -1;
}

void test_strcmp() {
    char *s[] = {
         "hello world"
        ,"these are not the droids you are looking for"
        ,""
        ,""
    };

    char *z[] = {
         "hello world!"
        ,"these are not the droids you are looking for"
        ,""
        ,"o" 
    };

    printf("Testing strcmp\n");

    for (int i = 0; i < 4; i++) {
        int res = strcmp(s[i], z[i]);
        int ftr = ft_strcmp(s[i], z[i]);
        bool cmp = gelt(res) == gelt(ftr);
        expect(cmp);
        if (!cmp)
            printf("\
      expected len: %d\n\
      received len: %d\n\
      for string s: \"%s\"\n\
      for string z: \"%s\"\n\
", res, ftr, s[i], z[i]);
    }

    return;
}


void expect(bool res) {
    static int c = 0;

    if (res) {
        printf("%.2d - OK\n", c);
    } else {
        printf("%.2d - KO\n", c);
    }
    c = c + 1;
}
