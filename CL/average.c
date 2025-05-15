#include <stdio.h>

// 求平均数
int main()
{
    int sum = 0;
    int n = 0;
    int x = 0;

    printf("请输入正整数（含0，输入负数结束输入）：");

    scanf("%d", &x);
    while (x >= 0) {
        n++;
        sum += x;
        scanf("%d", &x);
    }

    if (n > 0) {
        printf("平均数为：%lf", 1.0 * sum / n);
    } else {
        printf("无效输入");
    }

    return 0;
}