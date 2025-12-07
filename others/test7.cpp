#include <stdio.h>

int is_prime(int num)
{
    int i;
    int ret = 1;

    if (num <= 1) ret = 0;
    if (num == 2) ret = 1;
    if (num % 2 == 0 && num != 2) ret = 0;

    for (i = 3; i < num / 2; i += 2)
    {
        if (num % i == 0) {
            ret = 0;
        }
    }

    return ret;
}


int main()
{
    int count = 0;
    int i;

    int a, b, c, d;
    printf("输入4个正整数：");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int sum[6] = {a + b, a + c, a + d, b + c, b+ d, c + d};
    int size = sizeof(sum) / sizeof(int);

    for (i = 0; i < size; i++) {
        printf("sum[%d]=%d,", i, sum[i]);
    }

    printf("\n");

    for (i = 0; i < 6; i++) {
        if (is_prime(sum[i])) {
            count++;
        }
    }

    printf("4个正整数两两之和有%d个质数。", count);
    
    return 0;
}