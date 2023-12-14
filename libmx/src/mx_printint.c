#include "../inc/libmx.h"

void mx_printint(int n) {
    if(n < 0) {
        mx_printchar('-');
        n = -n;
    } else if(n == 0) {
        mx_printchar('0');
        return;
    } else if(n == -2147483648) {
        mx_printstr("-2147483648");
        return;
    } else if(n == 2147483647) {
        mx_printstr("2147483647");
        return;
    }
    int m = n;
    int k = 0;
    while(m > 0) {
        m /= 10;
        k++;
    }
    char a[k];
    for (int i = k - 1; i >= 0; i--) {
        a[i] = n % 10 + 48;
        n /= 10;
    }
    for (int i = 0; i < k; i++) {
        mx_printchar(a[i]);
    }
}

