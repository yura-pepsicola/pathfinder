#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    void *temp;
    if(!lst) return NULL;
    for (;;) {
        int k = 0;
        for (t_list *j = lst; j -> next; j = j -> next) {
            if (cmp(j -> data, j -> next -> data)) {
                temp = j -> data;
                j -> data = j -> next -> data;
                j -> next -> data = temp;
                k = 1;
            }
        }
        if (k == 0) break;
    }
    return lst;
}
