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
            t_list *paths = mx_create_node(mx_create_node(&(nodes[e])));
            for(int i = 0; i < node_count - 1; i++) {
                if(paths == NULL) {
                    break;
                }
                t_list *path = paths->data;
                node_t *last_node = path->data;
                t_list *neighbours = NULL;
                node_t *last_neighbour;
                for(int j = 0; j < bridge_count; j++) {
                    node_t *neighbour;
                    if(bridges[j].next != last_node && bridges[j].prev != last_node) {
                        continue;
                    }
                    if(bridges[j].next == last_node) {
                        neighbour = bridges[j].prev;
                    } else {
                        neighbour = bridges[j].next;
                    }
                    if(neighbour->price + bridges[j].price > last_node->price) {
                        continue;
                    }
                    last_neighbour = neighbour;
                    mx_push_back(&neighbours, last_neighbour);
                }
                if(neighbours == NULL) {
                    continue;
                }
                for(t_list *j = neighbours; j; j = j->next) {
                    t_list *new_path = mx_list_copy(path);
                    mx_push_front(&new_path, j->data);
                    mx_push_back(&paths, new_path);
                }
                mx_list_clear(&neighbours);
                mx_list_clear(((t_list **)&(paths->data)));
                mx_pop_front(&paths);
            }
            for(t_list *j = paths; j; j = j->next) {
                mx_paths_output(j->data);
                mx_list_clear((t_list **)&(j->data));
            }
            mx_list_clear(&paths);
        }
    }
    
}
