#include "pathfinder.h"

void mx_check_empty_file(char *file_name) {
    int length = 0, fd;
    char buff;
    fd = open(file_name, O_RDONLY);
    while (read(fd, &buff, 1)) {
        length++;
    }
    if(length == 0) {
        mx_sys_error("error: file ");
        mx_sys_error(file_name);
        mx_sys_error(" is empty\n");
        exit(1);
    }
}
