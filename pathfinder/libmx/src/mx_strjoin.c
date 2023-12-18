#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2){
    if(!s1 & !s2) return NULL;
    else if(!s1) return mx_strdup(s2);
    else if(!s2) return mx_strdup(s1);
    char *new_str = mx_strnew((mx_strlen(s1) + mx_strlen(s2)));
    new_str = mx_strdup(s1);
    mx_strcat(new_str, s2);
    return new_str;
}
