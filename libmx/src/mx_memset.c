#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    char byte = c;
    char *p = b;
    for(size_t i = 0; i < len; i++) {
        p[i] = byte;
    }
    return b;
}
