#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if(!(str && sub && replace)) return NULL;
    int c_substr = mx_count_substr(str, sub);
    int len = mx_strlen(str) - mx_strlen(sub)*c_substr + c_substr*mx_strlen(replace);
    int substr_i = mx_get_substr_index(str, sub);
    char *new_str = mx_strnew(len), *res_str = new_str;
    while(substr_i != -1) {
        mx_strncpy(new_str, str, substr_i);
        str += substr_i;
        new_str += substr_i;
        str += mx_strlen(sub);
        mx_strncpy(new_str, replace, mx_strlen(replace));
        new_str += mx_strlen(replace);
        substr_i = mx_get_substr_index(str, sub);
    }
    mx_strcpy(new_str, str);
    return res_str;
}
