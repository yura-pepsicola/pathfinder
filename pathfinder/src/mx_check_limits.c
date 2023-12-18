#include "pathfinder.h"

bool mx_check_limits(bridge_t *bridges, int bridge_count) {
    long max = 0;
    for(int i = 0; i < bridge_count; i++) {
        max += bridges[i].price; 
        if(max > INT_MAX || max < 0) {
            return false;
        }
    }
    return true;
}
