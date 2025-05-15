#include <stdio.h>

int main()
{
    // 初始化
    int price = 0;
    int bill = 0;

    // 读入金额和票面
    printf("请输入金额（元）：");
    scanf("%d", &price);
    printf("请输入票面（元）：");
    scanf("%d", &bill);

    // 计算找零
    if (bill >= price){
        printf("应找您%d元\n", bill - price);
    } else {
        printf("您的钱不够。");
    }

    return 0;
}