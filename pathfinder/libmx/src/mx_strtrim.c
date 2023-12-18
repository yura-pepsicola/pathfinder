#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if(!str) return NULL;
    int start = 0, finish = 0;
    char *new_string;
    for(int i = 0; i < mx_strlen(str); i++) {
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == '\r') start++;
        else break;
    }
    for(int i = mx_strlen(str) - 1; i >= 0; i--) {
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == '\r') finish++;
        else break;
    }
    if(mx_strlen(str) - finish < start) {
        return mx_strnew(0);
    }
    new_string = mx_strnew(mx_strlen(str) - start - finish);
    for(int i = start, j = 0; i < mx_strlen(str) - finish; i++, j++){
        new_string[j] = str[i];
    }    
    return new_string;
}
