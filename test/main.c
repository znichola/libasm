#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "libasm.h"

void expect(bool res);

void test_strlen();
void test_strcmp();
void test_strcpy();
void test_strdup();
void test_write();

int main() {
    test_strlen();
    test_strcmp();
    test_strcpy();
    test_strdup();
    test_write();

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
         "z"
        ,""
        ,"longer"
        ,"this is longe"
        ,"a"
        ,"B"
        ,""
        ,"o"
        ,"123"
    };

    char *z[] = {
         ""
        ,"y"
        ,"longe"
        ,"this is longer"
        ,"A"
        ,"b"
        ,"" 
        ,"o" 
        ,"1"
    };

    printf("Testing strcmp\n");

    for (int i = 0; i < 9; i++) {
        int res = strcmp(s[i], z[i]);
        int ftr = ft_strcmp(s[i], z[i]);
        bool cmp = gelt(res) == gelt(ftr);
        expect(cmp);
        if (!cmp)
            printf("\
      expected : %d hex: %#x\n\
      received : %d hex: %#x\n\
      string s : \"%s\"\n\
      string z : \"%s\"\n\
", res, res, ftr, ftr, s[i], z[i]);
    }

    return;
}

void test_strcpy() {
    char *s[] = {
         ""
        ,"a"
        ,"B"
        ,"123123o"
        ,"\n\t\r\n"
        ,"longer than this thing"
        ,"zero byte in \0\0 the middle"
    };

    char *d1 = malloc(200 * sizeof(char));
    char *d2 = malloc(200 * sizeof(char));

    printf("Testing strcpy\n");

    for (int i = 0; i < 7; i++) {
        bzero(d1, 200 * sizeof(char));
        bzero(d2, 200 * sizeof(char));
        if (i == 0) // to check it writes the \0 for empty string
            d2[0] = '#'; 
        char *exp =    strcpy(d1, s[i]);
        char *res = ft_strcpy(d2, s[i]);
        int   cmp = memcmp(exp, res, 200 * sizeof(char));

        expect(cmp == 0);
        if (!(cmp == 0))
            printf("\
      expected : \"%s\"\n\
      received : \"%s\"\n\
      hex      : res %p d2 %p\n\
", exp, res, res, d2);
    }

    free(d1);
    free(d2);
    return;
}

void test_strdup() {
    char *s[] = {
         ""
        ,"a"
        ,"#"
        ,"p"
        ,"ab"
        ,"\n\t\r\n"
        ,"some long string for testing"
        ,"🤖👋©←°(❁´◡`❁)"
    };

    printf("Testing strdup\n");

    for (int i = 0; i < 8; i++) {
        char *exp =    strdup(s[i]);
        char *res = ft_strdup(s[i]);

        int  cmp  = memcmp(exp, res, strlen(s[i]) * sizeof(char));
        int  cmp2 = strlen(exp) - strlen(res); // test ending \0
        cmp = cmp + cmp2;
        expect(cmp == 0);
        if (!(cmp == 0)) {
            printf("\
      expected : \"%s\"\n\
      received : \"", exp);
        fflush(stdout);
        write(1, res, strlen(s[i]));
        write(1, &"\"\n", 2);
        }
        if (cmp == 0 && exp == 0) {
            write(1, &"malloc OK\n", 10);
        }
        free(exp);
        free(res);
    }
}

void test_write() {
    char *s[] = {
         ""
        ,"1"
        ,"123"
        ,"\ttab"
        ,"long line to test"
        ,"🤖👋©←°(❁´◡`❁)"
    };
    printf("Testing write\n");
    fflush(stdout);

    for (int i = 0; i < 6; i++) {
        char l = strlen(s[i]);
        write(1, "expected: \"", 11);
        char exp = write(1, s[i], l);
        write(1, "\"\n written: \"", 13);
        char res = ft_write(1, s[i], l);
        write(1, "\"\n\n", 3);
        char cmp = exp - res;
        expect(cmp == 0);
        fflush(stdout);
        if (!(cmp == 0))
            printf("\
      expected : %d\n\
      received : %d\n", exp, res);
    }
    printf("Testing write, errors\n");
    char exp =    write(4, &"test", 4);
    char res = ft_write(4, &"test", 4);
    int cmp = exp - res;
    expect(cmp == 0);
    if (cmp)
        printf("\
      expected : %d\n\
      received : %d\n", exp, res);
}

void test_read() {
    printf("Testing read\n");
    char b[1000] = {0};
    (void)b;
    for (int i = 0; i < 2; i++) {

    }
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
