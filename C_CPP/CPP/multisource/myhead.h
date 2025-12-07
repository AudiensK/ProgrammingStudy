#ifndef _MYHEAD_H
#define _MYHEAD_H

#include <iostream>

// 普通类
class MyClass1
{
private:
    int a = 10;
public:
    // 类内定义
    void log1()
    {
        std::cout << a << std::endl;
    }

    // 在头文件中进行类外定义
    void log2(); 

    // 在源文件中进行类外定义
    void log3();
    // 大函数建议在源文件中进行类外定义
};

// 在头文件中进行类外定义
// void MyClass1::log2()
inline void MyClass1::log2() // 必须加 inline!
{
    std::cout << a << std::endl;
}
// 防止违反 ODR（单一定义规则），允许多个翻译单元包含相同定义，编译器会合并这些定义
// 头文件本身不是编译单元，但当它被多个源文件包含时，多个源文件会包含重复定义的成员函数

// 模板类
template<typename T>
class MyClass2
{
private:
    int a = 10;
public:
    // 模板类成员函数必须在头文件中定义
    void log4(T a);

    // 可以直接类内定义
    void log4(T a, T b)
    {
        std::cout << a + b << std::endl;
    }
};

// 模板类成员函数必须定义在头文件中
template<typename T>
void MyClass2<T>::log4(T a)
{
    std::cout << a << std::endl;
}

#endif