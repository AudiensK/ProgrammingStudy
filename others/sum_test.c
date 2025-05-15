#include <stdio.h>

int main()
{
    int integer, sum;
    printf("请输入第一个整数：");
    scanf("%d", &integer);  // %d 表示十进制整数
    sum = integer;
    printf("请输入第二个整数：");
    scanf("%d", &integer);  // &是取值符号，为后面变量取值
    sum = sum + integer;
    printf("请输入第三个整数：");
    scanf("%d", &integer);  // scanf 表示从键盘读取输入
    sum = sum + integer;
    printf("两数之和是%d .\n", sum);
    return 0;
}
