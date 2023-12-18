#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long res = 0;
    for (int i = 0; hex[i] != '\0'; i++) {
        res *= 16;
        if (hex[i] >= '0' && hex[i] <= '9') {
            res += hex[i] - '0';
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            res += hex[i] - 'a' + 10;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            res += hex[i] - 'A' + 10;
        }
    }
    return res;
}

