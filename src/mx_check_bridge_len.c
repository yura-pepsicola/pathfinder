#include "pathfinder.h"

void mx_check_bridge_len(char **lines) {
    char **line = NULL, *bridge_len = NULL;
    long count = 0;
    for (int i = 1; lines[i] != NULL; i++) {
        line = mx_strsplit(lines[i], '-');
        bridge_len = mx_strdup(line[1]);
        mx_del_strarr(&line);
        line = mx_strsplit(bridge_len, ',');
        mx_strdel(&bridge_len);
        count = count + mx_atoi(line[1]);
        if (count > INT_MAX) {
            mx_sys_error("error: sum of bridges lengths is too big\n");
            exit(1);
        }    
        mx_del_strarr(&line);
    }
}
    
