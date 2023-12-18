#include "pathfinder.h"

void mx_nodes_init(node_t *nodes, int node_count) {
    for(int i = 0; i < node_count; i++) {
        nodes[i].name = NULL;
        nodes[i].price = INT_MAX;
    }
}
