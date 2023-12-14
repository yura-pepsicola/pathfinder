#include "pathfinder.h"

void mx_check_cmd_args(int argc) {
    if(argc != 2) {
        mx_sys_error("usage: ./pathfinder [filename]\n");
        exit(1);
    }
}
