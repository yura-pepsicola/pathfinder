#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    char str[4];
    int k = 0;
    if(c<128) {
        str[0] = (char)c;
        k = 1;
    }
    else if(c < 0x800) {
        str[1] = 128 | (c & 63);
        str[0] = 192 | ((c >> 6) & 31);
        k = 2;
    }
    else if(c < 0x10000) {
        str[2] = 128 | (c & 63);
        str[1] = 128 | ((c >> 6) & 63);
        str[0] = 0xE0 | ((c >> 12) & 15);
        k = 3;
    }
    else if(c < 0x200000) {
        str[3] = 128 | (c & 63);
        str[2] = 128 | ((c >> 6) & 63);
        str[1] = 128 | ((c >> 12) & 63);
        str[0] = 240 | ((c >> 18) & 7);
        k = 4;
    }
    write(1, str, k);
}



