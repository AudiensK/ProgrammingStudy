#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");

    int price = 0;

    printf("请输入金额（元）：");
    scanf("%d", &price);

    int change = 100 - price;

    printf("找您%d元。\n", change);

}
