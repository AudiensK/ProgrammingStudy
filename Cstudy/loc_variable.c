#include <stdio.h>

int a = 10;

int double_num(int a);
void aa(void);

int main()
{
    a = double_num(a);
    printf("loc1:%d\n", a);
    aa();

    int b = 11;
    int c = 44;
    {
        b = 12;  // 之前对b的赋值其实是在对外部变量b赋值；
        int b = 22;  // 内部定义了一个同名变量b；
        b = 33;  // 之后所有对变量b的赋值都不会影响外部的变量b；
        c = 55;  // 在大括号内没有重新定义变量c，这里对c的赋值会影响外部的c；
        // 为了避免误会，增强代码可读性，尽量不要定义同名局部变量。
        printf("b1:%d\nc1:%d\n", b, c);
    }
    printf("b2:%d\nc2:%d\n", b, c);

    for (int i = 0; i < 2; i++) {
        printf("i:%d", i);
    }
    // printf("i:%d", i);  // i为for循环的局部变量，因此这条代码无法找到变量i。

    return 0;
}

int double_num(int a)
{
    printf("loc2:%d\n", a);

    return a * 2;
}

void aa(void)
{
    printf("glo:%d\n", a);
}