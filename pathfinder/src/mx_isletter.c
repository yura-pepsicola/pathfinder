#include "../inc/pathfinder.h"

bool mx_isletter(int c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        return true;
    }
    else {
        return false;
    }
        
}
