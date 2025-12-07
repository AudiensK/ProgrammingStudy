#include <iostream>

// 声明外部变量
extern int a;
// 声明函数原型
void log1(int a);

// 多源文件编译时，如果存在同名全局函数签名相同或同名全局变量，编译无法通过
// int a = 10; // file.cpp中有同名全局变量
// int log1(int a) // file.cpp中同名全局函数(名字和参数一样，返回类型对签名没影响)
// {
//     std::cout << a << std::endl;
//     return 0;
// }

// 单一定义规则（ODR）：\
C/C++ 要求全局作用域中相同签名的函数只能有一个定义。\
签名包括：函数名、参数类型（不包括返回类型）。
void log1() // 同名但是参数不同，签名不同
{
    std::cout << 9 << std::endl;
}

// 1.使用 static 限制作用域
static int b = 6;

// 2.使用命名空间（C++ 推荐）
namespace { // 使用匿名命名空间
    void log2(int a)
    {
        std::cout << a << std::endl;
    }
}

// 3.使用不同的名字

int main()
{
    log1(a);
    log1();
    // 使用匿名命名空间内的函数
    log2(b); // 不需要也无法使用作用域符

    return 0;
}

// g++ main.cpp file.cpp -o main.exe