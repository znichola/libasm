#ifndef LIBASM_H
# define LIBASM_H

#include <stdlib.h> // for malloc

ssize_t ft_read(int fildes, void *buf, size_t nbytes);
int     ft_strcmp(const char *s1, const char *s2);
char   *ft_strcpy(char *dest, const char *src);
char   *ft_strdup(const char *s);
size_t  ft_strlen(char *s);
ssize_t ft_write(int fd, const void *buf, size_t count);

#endif // LIBASM_H
