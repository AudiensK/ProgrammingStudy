#include <stdio.h>

// 函数是一块代码，接受零个或多个参数，做一件事情，并返回零个或一个值
void sum(int begin, int end)  // 函数头，void为返回类型，sum为函数名，(int begin, int end)为参数表，即使没有参数也需要()，表示函数调用。
{                             // 大括号包含的代码为函数体
    int i;
    int sum = 0;
    for (i = begin; i <= end; i ++) {
        sum += i;
    }
    printf("%d到%d的和是%d\n", begin, end, sum);
}

int main()
{
    sum(1, 10);
    sum(15, 25);
    sum(20, 30);    

    return 0;
}