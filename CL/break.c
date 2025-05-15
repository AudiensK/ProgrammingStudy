#include <stdio.h>

int main()
{
    for (int i = 0; i < 5; i++) {
        for (int i1 = 0; i1 < 2; i1++) {
            if (i1 == 1) {
                printf("1");
                break;
            }
        }
        printf("2");
        break;        
    }

    return 0;
}