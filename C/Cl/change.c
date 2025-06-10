#include <stdio.h>

int main()
{
    /* 变量类型 + 变量名（标识符） 定义变量；= 号用于赋值；
    sc只能在程式开头定义变量，c99可以在任何位置定义变量 */
    int price = 0;  // 变量使用前需要归零，否则会直接读取内存中的读数

    printf("请输入金额（元）：");  // printf和scanf中的f相当于formatted（格式化的）
    scanf("%d", &price);  // scanf函数读取格式化输入，%d占位符，读取十进制整数；注意price前的&（指针相关）；
    // 上面的scanf读取的如果不是数字，则会读取price变量的默认值，读取浮点数则会取整数（舍弃.后面的数）
    int change = 100 - price;  

    printf("找您%d元。\n", change);

    return 0;
}