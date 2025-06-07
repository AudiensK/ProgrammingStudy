#include <stdio.h>


void recursive(int r)
{
    printf("r=%d\n", r);

    r--;

    if (r > 0) {
        recursive(r);
    }
    
}


int main(void)
{
    int a = 10;
    recursive(a);

    return 0;
}