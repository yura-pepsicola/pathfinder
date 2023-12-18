#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    if(!(*head)) return;
    if(!((*head) -> next)) {
        free(*head);
        return;
    }
    t_list *buf_list = *head;
    if((buf_list) -> next) {
        while(((buf_list) -> next) -> next) {
            buf_list = (buf_list -> next);
        }
        free((buf_list) -> next);
    }
    (buf_list) -> next = NULL;
}
