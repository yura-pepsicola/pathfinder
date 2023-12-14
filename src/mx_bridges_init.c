#include "pathfinder.h"

void mx_bridges_init(bridge_t *bridges, int bridge_count) {
    for(int i=0;i<bridge_count;i++)
    {
        bridges[i].next = NULL;
        bridges[i].prev = NULL;
        bridges[i].price = 0;
    }
}
