#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
    char *temp;
    int s_operations = 0;
    for (int i = 0; i < size - 1; i++) {
        int k = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                s_operations++;
                k = 1;
                if (k == 0) break;
            }
        }
    }
    return s_operations;
}


