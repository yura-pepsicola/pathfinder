#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    if(!s) return;
    int str_length = mx_strlen(s);
    for(int i = 0; i < str_length/2; i++) {
        mx_swap_char(&s[i], &s[str_length-i-1]);
    }
}
