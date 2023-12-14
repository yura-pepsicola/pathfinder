#include "pathfinder.h"

void mx_file_parse(node_t *nodes, char **array, int node_count, bridge_t *bridges, int bridge_count) {
    mx_nodes_init(nodes, node_count);
    mx_bridges_init(bridges, bridge_count);
    int i = 1;
    while (array[i] != NULL) {
        char **piece = mx_strsplit(array[i], '-');
        char **modpiece = mx_strsplit(piece[1], ',');
        int index = mx_add_node(nodes, piece[0], node_count);
        int index2 = mx_add_node(nodes, modpiece[0], node_count);
        if(index < 0 || index2 < 0) {
            mx_sys_error("error: invalid number of islands\n");
            exit(1);
        }
        bridges[i - 1].next = &(nodes[index2]);
        bridges[i - 1].prev = &(nodes[index]);
        bridges[i - 1].price = mx_atoi(modpiece[1]);
        i++;
        mx_del_strarr(&piece);
        mx_del_strarr(&modpiece);
    }

}
