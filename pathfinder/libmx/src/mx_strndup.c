#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    if(!s1) {
        return mx_strnew(n);
    }
    char *new_string = (char *)mx_strnew(n);
    for (size_t i = 0; i < n && i < (size_t)mx_strlen(s1); i++) {
        new_string[i] = s1[i];
    }
    return new_string;
}
