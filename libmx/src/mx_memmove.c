#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *buf = mx_strnew(len);
    for(size_t i = 0; i < len; i++) {
        buf[i] = ((char *)src)[i];  
    }
    for(size_t i = 0; i < len; i++) {
        ((char *)dst)[i] = buf[i];
    }
    return dst;
}
