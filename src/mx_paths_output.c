#include "pathfinder.h"

void mx_paths_output(t_list *path) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    t_list *last = path;
    for(; last->next; last = last->next);
    mx_printstr(((node_t*)(path->data))->name);
    mx_printstr(" -> ");
    mx_printstr(((node_t*)(last->data))->name);
    mx_printstr("\n");
    mx_printstr("Route: ");
    for(t_list *i = path; i; i = i->next) {
        mx_printstr(((node_t*)(i->data))->name);
        if(i->next != NULL) {
            mx_printstr(" -> ");
        }
    }
    mx_printstr("\n");
    mx_printstr("Distance: ");
    int price = 0;
    if(path->next->next != NULL) {
        for(t_list *i = path; i->next; i = i->next) {
            price += ((node_t*)(i->next->data))->price - ((node_t*)(i->data))->price;
            mx_printint(((node_t*)(i->next->data))->price - ((node_t*)(i->data))->price);
            if(i->next->next != NULL) {
                mx_printstr(" + ");
            }
        }
        mx_printstr(" = ");   
    } else {
        price = ((node_t*)(path->next->data))->price;
    }
    mx_printint(price);
    mx_printstr("\n");
    mx_printstr("========================================\n");
}
