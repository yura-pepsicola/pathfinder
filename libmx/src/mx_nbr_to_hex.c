#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    unsigned long m = nbr;
    int k = 0;
    int rmndr;
    while(m > 0) {
        m /= 16;
        k++;
    }
    char *res = mx_strnew(k);
    for (int i = k - 1; i >= 0; i--) {
        rmndr = nbr % 16;
        nbr /= 16;
        if (rmndr < 10) {
            res[i] = rmndr + '0';
        }
        else if (rmndr < 16) {
            res[i] = rmndr + 'a' - 10;
        }
    }
    return res;
}


    


