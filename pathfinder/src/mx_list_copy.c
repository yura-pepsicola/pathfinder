#include "pathfinder.h"

t_list *mx_list_copy(t_list *list) {
    t_list *result = NULL;
    for(t_list *i = list; i; i = i->next) {
        mx_push_back(&result, i->data);
    }
    return result;
}
