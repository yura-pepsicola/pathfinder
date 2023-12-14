#include "../inc/pathfinder.h"

bool mx_isnumber(char *line) {
    for(int i = 0; line[i] != '\0'; i++) {
        if(line[0] == '-') {
            continue;
        }
        if (!mx_isdigit(line[i])) {
            return false;
        }
    }   
    return true;
}
