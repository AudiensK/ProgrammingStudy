// 在函数定义时，有时会存在有参数名但在函数体里并不使用，或者只有类型声明而没有参数名的情况，\
这类参数就被称作占位参数。它的主要作用是维持接口的兼容性，或者用于函数重载时的区分。

#include <iostream>

void log(int x)
{
    std::cout << "处理整数: " << x << std::endl;
}

void log(int x, int)
{
    std::cout << "处理两个整数（第二个被忽略）：" << x << std::endl;
}

int main()
{
    log(1);
    log(1, 2);

    return 0;
}