#include <stdio.h>

int main()
{
    const double RATE = 8.25;
    const int STANDARD = 40;
    double pay = 0.0;
    int hour = 0;

    printf("请输入工作时间（小时）:");
    scanf("%d", &hour);
    printf("\n");

    if (hour > STANDARD)  // if（）和else后面可以不接{}而直接接后面的语句，以;结尾，相比于{}更简洁，但是只能接一条。
        pay = STANDARD * RATE + 
        (hour - STANDARD) * (RATE * 1.5);
    else
        pay = hour * RATE;  // 使用{}虽然冗长，但可读性更好，可以执行多条语句。

    printf("应付工资%f元\n", pay);

    return 0;
}