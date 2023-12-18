#include "pathfinder.h"

int mx_add_node(node_t *nodes, char *name, int node_count) {
    for(int i = 0; i < node_count; i++) {
        if(nodes[i].name == NULL) {
            nodes[i].name = mx_strdup(name);
            return i;
        }
        if(mx_strcmp(nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}
