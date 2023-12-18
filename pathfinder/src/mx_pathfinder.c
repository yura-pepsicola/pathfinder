#include "pathfinder.h"

void mx_pathfinder(node_t *nodes, int node_count, bridge_t *bridges, int bridge_count) {
    for(int k = 0; k < node_count - 1; k++) {
        for(int i = 0; i < node_count; i++) {
            nodes[i].price = INT_MAX;
        }
        nodes[k].price = 0;
        for(int i = 0; i < node_count - 1; i++) {
            for(int j = 0; j < bridge_count; j++) {
                if(bridges[j].prev->price != INT_MAX) {
                    int new_price = bridges[j].price + bridges[j].prev->price;
                    if(new_price < bridges[j].next->price) {
                        bridges[j].next->price = new_price;
                    }
                }
                if(bridges[j].next->price != INT_MAX) {
                    int new_price = bridges[j].price + bridges[j].next->price;
                    if(new_price < bridges[j].prev->price) {
                        bridges[j].prev->price = new_price;
                    }
                }
            }
        }
        for(int e = k + 1; e < node_count; e++) {
            mx_rec_print(nodes, bridges, mx_create_node(&nodes[k]), &nodes[e], 0, bridge_count);
        }
    }
    
}
