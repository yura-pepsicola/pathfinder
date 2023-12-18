#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int haystack_len = mx_strlen(haystack), needle_len = mx_strlen(needle), i;
    for(i = 0; i <= haystack_len - needle_len; i++) {
        int j;
        for(j = 0; j < needle_len; j++) {
            if(haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == needle_len) {
            return (char *)(haystack + i);
        }
    }
    return NULL;
}
