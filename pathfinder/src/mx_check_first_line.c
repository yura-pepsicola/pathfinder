#include "pathfinder.h"

void mx_check_first_line(char *line) {
    if(!mx_isnumber(line) || mx_atoi(line) < 0) {
        mx_sys_error("error: line 1 is not valid\n");
        exit(1);
    }
}
