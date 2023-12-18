#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if(buf_size < 0 || fd < 0) return -2;
    if(!lineptr) return -1;
    static char *rmndr;
    char *str = *lineptr;
    if(rmndr != NULL) {
        mx_strcpy(str, rmndr);
        str += mx_strlen(rmndr);
        mx_strdel(&rmndr);
        rmndr = NULL;
    }
    char *c = mx_strnew((int)buf_size);
    int len = 0, count = 1, delim_i;
    while(count != 0) {
        count = read(fd, c, buf_size);
        if(count == 0) break;
        delim_i = mx_get_char_index(c, delim);
        if(delim_i != -1) { 
            mx_strncpy(str, c, delim_i);
            if(delim_i < count) {
                c += delim_i + 1;
                rmndr = mx_strndup(c, count - delim_i);
            }
            len += delim_i;
            break;
        }
        mx_strcpy(str, c);
        str += count;
        len += count;
    }
    return len;
}
