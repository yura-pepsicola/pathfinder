#include "pathfinder.h"

void mx_check_lines(char **lines) {
    int minus = 0;
    int comma = minus;
    int match = comma;
    bool status;
    for (int i = 1; lines[i] != NULL; i++) {
        for (int j = 0; lines[i][j] != '\0'; j++) {
            if (lines[i][j] == '-') {
                minus++;
            }                
            if (lines[i][j] == ',' && minus == 1) {
                comma++;
            }
        }
        if (minus != 1 || comma != 1) {
            mx_sys_error("error: line ");
            mx_sys_error(mx_itoa(i + 1));
            mx_sys_error(" is not valid\n");
            exit(1);
        }
        minus = 0;
        comma = minus;
        for (int j = 0; lines[i][j] != '-'; j++) {
            if (!mx_isletter(lines[i][j])){
                mx_sys_error("error: line ");
                mx_sys_error(mx_itoa(i + 1));
                mx_sys_error(" is not valid\n");
                exit(1);
            }
        }
        status = false;
        for (int j = 0; lines[i][j] != ','; j++) {
            if (lines[i][j] == '-') {
                status = true;
            }
            if (status && !mx_isletter(lines[i][j + 1])) {
                mx_sys_error("error: line ");
                mx_sys_error(mx_itoa(i + 1));
                mx_sys_error(" is not valid\n");
                exit(1);
            }
            status = false;
        }
        status = false;
        for (int j = 0; lines[i][j] != '\0'; j++) {
            if (!status && lines[i][j] == ',') {
                status = true;
                j++;
            }
            if (status && !mx_isdigit(lines[i][j])) {
                mx_sys_error("error: line ");
                mx_sys_error(mx_itoa(i + 1));
                mx_sys_error(" is not valid\n");
                exit(1);
            }
        }
        status = false;
        int j = 0;
        while (lines[i][j] != '-') {
            j++;
        }
        for(int k = 0; k < j; k++) {
            if (lines[i][k] == lines[i][k + j + 1]) {
                match++;
            }        
        }  
        if (match == j && lines[i][match + j + 1] == ',')  {
            mx_sys_error("error: line ");
            mx_sys_error(mx_itoa(i + 1));
            mx_sys_error(" is not valid\n");
            exit(1);
        }
        match = 0; 
    }
}
