#include <stdio.h>

int main()
{
    int a,b;
    int i;
    int l;
    int ret;

    scanf("%d %d", &a, &b);

    if (a < b) {
        l = a;
    } else {
        l = b;
    }
    for (i = 1; i <= l; i++) {
        if (a % i == 0) {
            if (b % i == 0) {
                ret = i;
            }
        }
    }

    printf("gcd=%d", ret);

    return 0;
}