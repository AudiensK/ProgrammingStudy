#include <stdio.h>

int isPrime(int i)
{
    // 判断是否为素数
    int ret = 1;
    int k;
    for (k = 2; k < i; k ++) {
        if (i % k == 0) {
            ret = 0;
            break;
        }
    }

    return ret;  // 注意不要忘记返回值！！！(void类型函数无返回值)
}

int main()
{
    int m,n;  // 求从m到n所有素数和
    int sum = 0;
    int cnt = 0;
    int i;

    scanf("%d %d", &m, &n);
    // m = 10,n = 31;
    if (m == 1) m = 2;  // 1不是质数（素数）也不是合数
    for (i = m; i <= n; i ++) {
        
        // 素数求和，统计素数个数
        if (isPrime(i)) {
            printf("%d ", i);
            sum += i;
            cnt ++;
        }
    }
    // 输出结果
    printf("\n从%d到%d共有%d个素数，其和为%d。", m, n, cnt, sum);

    return 0;
}