#include "pathfinder.h"

void mx_check_no_file(int fd, char* file_name) {
    if(fd < 0) {
        mx_sys_error("error: file ");
        mx_sys_error(file_name); 
        mx_sys_error(" does not exist\n");
        exit(1);
    }
}
