#include "../inc/libmx.h"

void mx_printstr(const char *s) {
    int k = 0;
    while (s[k] != '\0') {
        k++;
    }
    write(1, s, k);
}


