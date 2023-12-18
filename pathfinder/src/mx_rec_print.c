#include "pathfinder.h"

void mx_rec_print(node_t *nodes, bridge_t *bridges, t_list *prev_path, node_t *last, int sum, int bridge_count) {
    t_list *prev_path_last = prev_path;
    for(; prev_path_last->next; prev_path_last = prev_path_last->next);
    node_t *last_node = prev_path_last->data;
    if(sum > last->price) {
        mx_list_clear(&prev_path);
        return;
    }
    if(last == prev_path_last->data) {
        mx_paths_output(prev_path);
        mx_list_clear(&prev_path);
        return;
    }
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
        // if(neighbour->price + bridges[j].price > last_node->price) {
        //     continue;
        // }
        t_list *new_path = mx_list_copy(prev_path);
        mx_push_back(&new_path, neighbour);
        mx_rec_print(nodes, bridges, new_path, last, sum + bridges[j].price, bridge_count);
        // mx_printstr(last_node->name);
        // mx_printstr(" ");
        // mx_printstr(neighbour->name);
        // mx_printstr("\n");
    }
    mx_list_clear(&prev_path);
}
