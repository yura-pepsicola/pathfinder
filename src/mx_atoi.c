#include "../inc/pathfinder.h"

int mx_atoi(char *str) {
    int minus = 1, num = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(i == 0 && str[i] == '-') {
            minus = -1;
            continue;
        }
        num = num * 10 + str[i] - '0';
    }
    return num * minus;
}
