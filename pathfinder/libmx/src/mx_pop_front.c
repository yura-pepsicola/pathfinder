#include "../inc/libmx.h"

void mx_pop_front(t_list **head) {
    if(!(*head)) return;
    if(!((*head) -> next)) {
        free(*head);
        *head = NULL;
        return;
    }
    t_list *buf = (*head) -> next;
    free(*head);
    *head = buf;
}
