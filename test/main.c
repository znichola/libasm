#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "libasm.h"

int error_count = 0;
void expect(bool res);

void test_strlen();
void test_strcmp();
void test_strcpy();
void test_strdup();
void test_write();
void test_read();

int main() {
/*
    test_strlen();
    test_strcmp();
    test_strcpy();
*/
    test_strdup();
/*
    test_write();
    test_read();
*/
    printf("TOTAL ERRORS: %d\n", error_count);
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

    for (int i = 0; i < 0; i++) {
        char *exp =    strdup(s[i]);
        char *res = ft_strdup(s[i]);

        int  cmp  = memcmp(exp, res, (strlen(s[i]) + 1) * sizeof(char));
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
    char *dup = ft_strdup("hello world");
    printf("testing dup \"%s\"\n", dup);
    free(dup);
    dup = ft_strdup("NO OOO ASDOASDOASODA");
    printf("testing dup \"%s\"\n", dup);
    free(dup);
    dup = ft_strdup("ZZZZZZZSSSSSSDSSDSDSKDJSKDJSLKJD");
    printf("testing dup \"%s\"\n", dup);
    free(dup);
    exit(0);
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
        ssize_t exp = write(1, s[i], l);
        write(1, "\"\n written: \"", 13);
        ssize_t res = ft_write(1, s[i], l);
        write(1, "\"\n\n", 3);
        ssize_t cmp = exp - res;
        expect(cmp == 0);
        fflush(stdout);
        if (!(cmp == 0))
            printf("\
      expected : %zd\n\
      received : %zd\n", exp, res);
    }

    printf("Testing write, errors\n");

    errno = 0;
    ssize_t exp =    write(4, &"test", 4);
    int ee = errno;
    errno = 0;
    ssize_t res = ft_write(4, &"test", 4);
    int er = errno;

    expect((exp == res) && (ee == er));
    if ((exp != res) || (ee != er))
        printf("\
      expected : %zd\n\
      received : %zd\n\
      ex errno : %d \"%s\"\n\
      rc errno : %d \"%s\"\n\
", exp, res, ee, strerror(ee), er, strerror(er));
}

void test_read() {
    char *s[] = {
         "test string on one line"
        ,"two\nlines of text\nor\tthree?\n"
        ,"🤖👋©←°(❁´◡`❁)\n"
    };
    int f[3] = {0};
    for (int i = 0; i < 3; i++) {
        char b[3] = {0};
        b[0] = 'f';
        b[1] = (char)i + '0';
        f[i] = open(b, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
        if (f[i] < 0) {
            write(2, &"error create test files\n", 24);
            return ;
        }
        write(f[i], s[i], strlen(s[i]));
        lseek(f[i], 0, 0); // reset to start of file
    }

    printf("Testing read\n");

    char exp[1000] = {0};
    char res[1000] = {0};
    for (int i = 0; i < 3; i++) {
        ssize_t e =    read(f[i], exp, 1000);
        lseek(f[i], 0, 0);
        ssize_t r = ft_read(f[i], res, 1000);

        int cmp = memcmp(exp, res, 1000 * sizeof(char));
        expect(e == r || cmp == 0);
        if (e != r || cmp != 0)
            printf("\
      expected : %.2zd \"%s\"\n\
      received : %.2zd \"%s\"\n\
", e, exp, r, res);
        bzero(exp, 1000);
        bzero(res, 1000);
    }

    for (int i = 0; i < 3; i++) {
        close(f[i]);
        char b[3] = {0};
        b[0] = 'f';
        b[1] = (char)i + '0';
        remove(b);
    }

    bzero(exp, 1000);
    bzero(res, 1000);

    printf("Testing read, errors\n");
    errno = 0;
    ssize_t e =    read(69, res, 1000);
    int ee = errno;
    errno = 0;
    lseek(4, 0, 0);
    ssize_t r = ft_read(69, res, 1000);
    int er = errno;
    expect((ee == er) && (e == r));
    if ((ee != er) || (e != r))
        printf("\
      expected : %zd \"%s\"\n\
      received : %zd \"%s\"\n\
      ex errno : %d \"%s\"\n\
      rc errno : %d \"%s\"\n\
",e, exp, r, res, ee, strerror(ee), er, strerror(er));
}

void expect(bool res) {
    static int c = 0;

    if (res) {
        printf("%.2d - OK\n", c);
    } else {
        printf("%.2d - KO\n", c);
        error_count += 1;
    }
    c = c + 1;
}
