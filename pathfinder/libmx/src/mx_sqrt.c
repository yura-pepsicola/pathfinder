#include "../inc/libmx.h"

int mx_sqrt(int x) {
    if(x <= 0) return 0;
    int k = 0;
    int n = 0;
    while(n < x) {
        k++;
        n = k * k;
    }
    if (n == x) return k;
    return 0;
}


