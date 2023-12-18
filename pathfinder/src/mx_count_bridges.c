#include "pathfinder.h"

int mx_count_bridges(char **array) {
    int j = 0;
    while(array[j] != NULL) {
        j++;
    }
    return j - 1;
}
