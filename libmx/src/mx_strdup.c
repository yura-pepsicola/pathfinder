#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    char *new_string = (char *)mx_strnew(mx_strlen(s1));
    return mx_strcpy(new_string, s1);
}
