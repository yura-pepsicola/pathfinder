#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *new_string = mx_strtrim(str);
    int xtra_spcs = 0;
    for(int i = 0; i < mx_strlen(new_string) - 1; i++) {
        if((new_string[i] == ' ' || new_string[i] == '\t' || new_string[i] == '\n' || new_string[i] == '\f' || new_string[i] == '\r') &&
            (new_string[i + 1] == ' ' || new_string[i + 1] == '\t' || new_string[i + 1] == '\n' || new_string[i + 1] == '\f' || new_string[i + 1] == '\r')) {
            xtra_spcs++;
        }
    }
    char *result_str;
    result_str = mx_strnew(mx_strlen(new_string) - xtra_spcs);
    for(int i = mx_strlen(new_string) - 1, j = mx_strlen(new_string) - xtra_spcs - 1; i >= 0; i--) {
        if((new_string[i] == ' ' || new_string[i] == '\t' || new_string[i] == '\n' || new_string[i] == '\f' || new_string[i] == '\r') &&
            (new_string[i - 1] == ' ' || new_string[i - 1] == '\t' || new_string[i - 1] == '\n' || new_string[i - 1] == '\f' || new_string[i - 1] == '\r')) {
            continue;
        }
        result_str[j] = new_string[i];
        j--;
    }
    return result_str;
}
