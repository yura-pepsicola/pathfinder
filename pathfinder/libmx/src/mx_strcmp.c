#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
    int res = 0;
    int strlen1 = 0;
    int strlen2 = 0;
    while (s1[strlen1] != '\0') {
        strlen1++;
    }
    while (s2[strlen2] != '\0') {
        strlen2++;
    }
    int maxlen;
    if (strlen1 > strlen2) maxlen = strlen1;
    else maxlen = strlen2;
    int i = 0;
    while (i < maxlen) {
        if (s2[i] == '\0') {
            res = s1[i];
            break;
        }
        else if (s1[i] == '\0') {
            res = 0 - s2[i];
            break;
        }
        else if (s1[i] != s2[i]) {
            res = s1[i] - s2[i];
            break;
        }
        i++;
    }
    return res;
}
