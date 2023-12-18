#include "pathfinder.h"

bool mx_check_duplicates(bridge_t *bridges, int bridge_count) {
    for(int i = 0; i < bridge_count - 1; i++) {
        for(int j = i + 1; j < bridge_count; j++) {
            if(bridges[i].next == bridges[j].next && bridges[i].prev == bridges[j].prev) {
                return false;
            }
            if(bridges[i].next == bridges[j].prev && bridges[i].prev == bridges[j].next) {
                return false;
            }
        }
    }
    return true;
}
