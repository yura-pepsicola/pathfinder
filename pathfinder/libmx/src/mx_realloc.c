#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if(malloc_size(ptr) > size) size = malloc_size(ptr);
    char *p_ptr = ptr, *new_pack = malloc(size);
    size_t usable_size = malloc_size(ptr);
    for(size_t i = 0; i < size && i < usable_size; i++) {
        new_pack[i] = p_ptr[i];
    }
    free(ptr);
    ptr = new_pack;
    return new_pack;
}
