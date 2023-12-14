#include "../inc/libmx.h"

int mx_get_char_index(const char *str, char c) {
    if(!str) return -2;
    int i;
    for (i = 0; i < mx_strlen(str); i++) {
        if(str[i] == c) break;
    }
    if(str[i] != c) return -1;
    return i;
}
