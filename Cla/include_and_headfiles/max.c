#include "max.h"

double max(int a, int b)
{
    int max;
    if (if_abtb(a, b)) {
        max = a;
    } else {
        max = b;
    }

    return max;
}

bool if_abtb(int a, int b)
{
    if (a > b) {
        return true;
    } else {
        return false;
    }
}