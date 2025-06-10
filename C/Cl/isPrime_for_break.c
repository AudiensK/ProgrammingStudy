#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int i;
    int isPrime = 1;
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            isPrime = 0;
            break;  // break跳出循环；continue跳过循环这一轮剩下的语句进入下一轮。
        }
    }

    if (isPrime == 1) {
        printf("是素数");
    } else {
        printf("不是素数");
    }

    return 0;
}