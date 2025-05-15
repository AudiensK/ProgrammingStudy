#include<stdio.h>

int main()
{
    const int AMOUNT = 100;  // const定义常量,常量名一般全部大写
    int a, b;
    a = 1;
    b = 2;
    scanf("pr ice%d, %d \n", &a, &b);
    // 分号内两个%d之间的逗号和空格也必须被scanf读取到，有逗号时可忽略空格,逗号和空格相当于分割；
    // 后面有空格或\n时在输入数据回车后必须输入其他任何数据才能继续；
    // 注意不要漏掉变量前的&。
    printf("%d, %d, %d, %d", a, b, AMOUNT, a + b);
    return 0;
}
