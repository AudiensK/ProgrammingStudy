// 函数重载（Function Overloading）是 C++ 的一项核心特性，\
它允许在同一作用域内定义多个同名但参数列表不同的函数。\
这一机制极大地提升了代码的可读性和灵活性，让开发者能够用相同的函数名处理不同类型或数量的参数。

// 核心概念\
相同函数名：多个函数共享同一个名称。\
不同参数列表：通过以下方式区分：\
    参数类型不同（如 int、double、std::string）。\
    参数数量不同（如 2 个参数 vs 3 个参数）。\
    参数顺序不同（如 (int, double) vs (double, int)）。\
返回值不参与重载：不能仅通过返回类型区分函数。

#include <iostream>


int add(int a, int b)
{
    return a + b;
}

void add(double *ret, int a, int b)
{
    *ret = a + b;
}

float add(float a, int b)
{
    return a + (float)b;
}


int main(void)
{
    using namespace std;

    double* ret;
    cout << add(1, 3) << endl;
    add(ret, 1, 3);
    cout << *ret << endl;
    // cout << add(1.0, 3) << endl;  // 1.0默认位双精度浮点数，而add参数需要float
    cout << add(1.1f, 3) << endl;  // 可以在数字后面加上f后缀表示float

    return 0;
}