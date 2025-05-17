#include <stdio.h>

int main()
{
    int num = 752846727;
    // scanf("%d", &num);

    int d = 1;
    int t = num;
    while (t > 9) {
        t /= 10;
        d *= 10;
    }

    while (d >= 1) {
        printf("%d", num / d);
        if (d > 1) {
            printf(",");
        }
        num %= d;
        d /= 10;
    }

    return 0;
}