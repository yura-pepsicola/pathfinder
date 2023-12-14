#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    if(!s) return NULL;
    for(size_t i = n - 1; i >= 0; i--) {
        if(((char *)s)[i] == (char)c) return &((char *)s)[i];
    }
    return NULL;
}
