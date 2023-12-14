#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if(!str || !sub) return -1;
    int k = 0;
    if(str[0] == '\0') return 0;
    int str_len = mx_strlen(str), sub_len = mx_strlen(sub), i;
    for(i = 0; i <= str_len - sub_len; i++) {
        int j;
        for(j = 0; j < sub_len; j++) {
            if(str[i + j] != sub[j]) {
                break;
            }
            if (j == sub_len - 1) {
                k++;
                break;
            }
        }
        
    }
    return k;
}
