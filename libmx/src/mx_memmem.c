#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    size_t i, j;
    if(!(big && little)) return NULL;
    for(i = 0; i <= big_len - little_len; i++) {
        for(j = 0; j < little_len; j++) {
            if(((char *)big)[i + j] != ((char *)little)[j]) {
                break;
            }
        }
        if (j == little_len) {
            return &((char *)big)[i];
        }
    }
    return NULL;
    // for(size_t i = 0; i < big_len; i++) {
    //     if(((char *)s)[i] == (char)c) return &((char *)s)[i];
    // }
    // return NULL;   
}
