#include "../inc/libmx.h"

int mx_get_substr_index(const char* str, const char *sub) {
    if(!str || !sub) return -2;
    int str_len = mx_strlen(str), sub_len = mx_strlen(sub), i;
    for(i = 0; i <= str_len - sub_len; i++) {
        int j;
        for(j = 0; j < sub_len; j++) {
            if(str[i + j] != sub[j]) {
                break;
            }
        }
        if (j == sub_len) {
            return i;
        }
    }
    return -1;
}
