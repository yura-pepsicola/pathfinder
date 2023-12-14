#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    char *p_s1 = (char *)s1;
    char *p_s2 = (char *)s2;
    int res = 0;
    for(size_t i = 0; i < n; i++) {
        if(!p_s2[i] && p_s1[i]) {
            res += p_s1[i];
        } else if(!p_s1[i] && p_s2[i]) {
            res += p_s2[i];
        }
        else res += p_s1[i] - p_s2[i];
    }
    return res;
}
