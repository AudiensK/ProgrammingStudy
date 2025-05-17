#include <stdio.h>

/*  函数原型
通常来说，需要把需要调用的函数放在前面，调用该函数的函数放在后面，
但是为了阅读方便等因素，可以在开头先声明一个函数，再把需要调用的函数在后面定义。
*/
void sum(int begin, int end);  // 声明
// void sum(int, int);  // 也可写成这样，编译器只会检测参数类型，不会检测参数名。
// void sum() 在传统C语言中表示参数不确定，避免这样声明函数原型；
// int f(void) 在括号内写void表示没有参数；

int main()  // int main()也是一个函数；
{
    sum(1, 10);
    // 调用函数时参数后面的逗号不是运算符，如果加个括号，如sum((1, 10))，则会先进行括号内运算再传入参数；
    sum(15, 25);
    sum(20, 30);    

    return 0;  // main函数返回的值是可以查看的，也是有意义的；
}

void sum(int begin, int end)  // 定义  // C语言不允许函数嵌套定义
{
    int i;
    int sum = 0;
    for (i = begin; i <= end; i ++) {
        sum += i;
    }
    printf("%d到%d之间的整数和是%d\n", begin, end, sum);
}

