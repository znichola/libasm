#include <stdlib.h>
#include <string.h>

char *	ft_strdup(const char *s)
{
    char *d = malloc(strlen(s) * sizeof(char));
    if (!d) return NULL;
    int i = 0;
    while (s[i]) {
        d[i] = s[i];
        i++;
    }
    d[i] = s[i];
    return d;
}
