#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    if(!file) return NULL;
    int desc = open(file, O_RDONLY);
    if(desc < 0) {
        close(desc);
        return NULL;
    }
    char c;
    int len = 0, count = 1;
    while(count > 0) {
        count = read(desc, &c, 1);
        len++;
    }
    close(desc);
    if(len <= 0) return NULL;
    char *str = mx_strnew(len);
    desc = open(file, O_RDONLY);
    read(desc, str, len);
    close(desc);
    return str;
}

