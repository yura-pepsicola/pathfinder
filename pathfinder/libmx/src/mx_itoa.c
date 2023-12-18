#include "../inc/libmx.h"

char *mx_itoa(int number) {
    int m = number, k = 0, i = 0, isNegative = 0;
    while(m) {
        m /= 10;
        k++;
    }
    char *res = mx_strnew(k);
    if (number == 0) {
        res[i++] = '0';
        res[i] = '\0';
        return res;
    }
    if (number < 0) {
        isNegative++;
        number = -number;
    }
    if(number == -2147483648) 
        return mx_strdup("-2147483648");
    while (number != 0) {
        int rem = number % 10;
        res[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        number = number / 10;
    }
    if (isNegative)
        res[i++] = '-';
    res[i] = '\0';
    mx_str_reverse(res);
    return res;
}

