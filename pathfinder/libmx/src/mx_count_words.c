#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (!str) return -1;
    int k = 0;
    int i = 0;
    while (str[i] != '\0') {
        while (str[i] == c) {
            i++;
        }
        if (str[i] != '\0') {
            k++;
        }
        while (str[i] != '\0' && str[i] != c) {
            i++;
        }
    }   
    return k;
}
