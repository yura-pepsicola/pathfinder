#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    if(*list == NULL) {
        *list = mx_create_node(data);
        return;
    }
    t_list *new_list = malloc(sizeof(t_list));
    t_list **buf_list = list;
    while((*buf_list) -> next) {
        buf_list = &((*buf_list) -> next);
    }
    new_list -> data = data;
    new_list -> next = NULL;
    (*buf_list) -> next = new_list;
}
