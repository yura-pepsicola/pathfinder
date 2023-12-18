#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if(!(arr && delim)) return;
    int i = 0;
    while (arr[i] != NULL) {
        mx_printstr(arr[i]);
        if(arr[i+1] != NULL) {
            mx_printstr(delim);
        }
        i++;
    }
}

