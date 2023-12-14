#include "pathfinder.h"

void mx_check_lines(char **lines) {
    int minus = 0;
    int comma = minus;
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
    }
    for (int i = 1; lines[i] != NULL; i++) {
        for (int j = 0; lines[i][j] != '-'; j++) {
            if (!mx_isletter(lines[i][j])){
                mx_sys_error("error: line ");
                mx_sys_error(mx_itoa(i));
                mx_sys_error(" is not valid\n");
                exit(1);
            }
        }
        if (!mx_isletter(lines[i][0])) {
            mx_sys_error("error: line ");
            mx_sys_error(mx_itoa(i));
            mx_sys_error(" is not valid\n");
            exit(1);
        }
    }
    bool status;
    for (int i = 1; lines[i] != NULL; i++) {
        status = false;
        for (int j = 0; lines[i][j] != ','; j++) {
            if (lines[i][j] == '-') {
                status = true;
            }
            if ((status == true) && (!mx_isletter(lines[i][j + 1]))) {
                mx_sys_error("error: line ");
                mx_sys_error(mx_itoa(i + 1));
                mx_sys_error(" is not valid\n");
                exit(1);
            }
            status = false;
        }
    }
    status = false;
    for (int i = 1; lines[i] != NULL; i++) {
        for (int j = 0; lines[i][j] != '\0'; j++) {
            if (lines[i][j] == ',') {
                status = true;
                j++;
            }
            if ((status == true) && (mx_isdigit(lines[i][j]) == false)) {
                mx_sys_error("error: line ");
                mx_sys_error(mx_itoa(i + 1));
                mx_sys_error(" is not valid\n");
                exit(1);
            }
            status = false;
        }
    }
    int i = 1;
    int match = 0;
    while (lines[i] != NULL) {
        int j = 0;
        while (lines[i][j] != '-') {
            j++;
        }
        for(int k = 0; k < j; k++) {
            if (lines[i][k] == lines[i][k+j+1]) {
                match++;
            }        
        }  
        if (match == j)  {
            mx_sys_error("error: line ");
            mx_sys_error(mx_itoa(i + 1));
            mx_sys_error(" is not valid\n");
            exit(1);
        } 
        i++;
        match = 0;
    }
}
