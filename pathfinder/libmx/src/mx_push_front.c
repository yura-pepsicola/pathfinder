#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data) { 
    if(*list == NULL) {
        *list = mx_create_node(data);
        return;
    }
    t_list *new_list = malloc(sizeof(t_list));
    new_list -> data = data;
    new_list -> next = *list;
    *list = new_list;
}
