#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);

    int cnt = 0;

    int isPrime = 1;
    if (n == 1 || (n % 2 == 0 && n != 2)) {  // 1和所有偶数不是素数
        isPrime = 0;
    }
    for (int i = 3; i < sqrt(n); i+=2) {  // sqrt(n)求n的平方根,需要 <math.h> 头文件
        // 进一步优化方法，能被已知的且小于n的素数整除的数也不是素数，该方法需要构建一张素数表。
        cnt ++;
        if (n % i == 0) {
            isPrime = 0;
            printf("i=%d\n", i);
            break;
        }
    }

    if (isPrime == 1) {
        printf("是素数");
    } else {
        printf("不是素数");
    }

    printf("\n循环次数：%d", cnt);

    return 0;
}