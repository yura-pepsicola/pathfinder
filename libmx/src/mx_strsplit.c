#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    int word_num = mx_count_words(s, c) + 1, j = 0;
    char **str_arr = malloc(word_num * 8);
    int i = mx_get_char_index(s, c);
    while(i != -1) {
        if(i > 0) {
            str_arr[j] = mx_strndup(s, i);
            j++;
            s += i;
        }
        i = mx_get_char_index(++s, c);
    }
    if(*s != '\0') {
        str_arr[word_num - 2] = mx_strdup(s);
    }
    str_arr[word_num - 1] = NULL;
    return str_arr;
}

