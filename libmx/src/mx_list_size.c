#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    if(list) {
        int count = 0;
        t_list *buf_list = list;
        while(buf_list) {
            count++;
            buf_list = (buf_list) -> next;
        }
        return count;
    }
    return 0;
}
