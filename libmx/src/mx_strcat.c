#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    for(int i = mx_strlen(s1), j = 0; i < (mx_strlen(s2) + mx_strlen(s1)); i++, j++) {
        s1[i] = s2[j];
    }
    s1[mx_strlen(s1) + mx_strlen(s2)] = '\0';
    return s1;
}
