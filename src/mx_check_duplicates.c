#include "pathfinder.h"

void mx_check_duplicates(char **lines) {
    int i = 1, match = 0;
    while (lines[i] != NULL) {
        int j = 0;
        while (lines[i][j] != ',') {
            j++;
        }
        for(int k = 0; k < j; k++) {
            if (lines[i+1] != NULL) {
                if (lines[i][k] == lines[i + 1][k]) {
                    match++;
                }
            }          
        }  
        if (match == j)  {
            mx_sys_error("error: duplicate bridges\n");
            exit(1);
        } 
        i++;
        match = 0;
    }
}
