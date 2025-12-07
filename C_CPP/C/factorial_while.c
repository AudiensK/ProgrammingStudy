#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int factor = 1;

    int i = 1;
    while (i <= n)
    {
        factor *= i;
        i++;
    }

    printf("%d!=%d\n", n, factor);

    return 0;
}