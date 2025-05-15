#include <stdio.h>

int main()
{
    int a,b;
    int i;
    int ret;

    // scanf("%d %d", &a, &b);
    a = 12;
    b = 24;

    // &&与；||或；！非
    for (i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            ret = i;
        }
    }

    printf("gcd=%d\n", ret);

    int c = 3>4 || 5<3;
    // int c = 3<4 || 5<3;
    printf("%d %d", c, !0);

    return 0;
}