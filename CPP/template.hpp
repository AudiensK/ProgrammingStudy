#ifndef _TEMPLATE_HPP_
#define _TEMPLATE_HPP_

// C++ 的模板是一种强大的特性，它允许你编写通用的、类型安全的代码，而不需要为不同的数据类型重复实现相同的逻辑。\
模板是 C++ 泛型编程（Generic Programming）的基础，广泛应用于标准库（如 STL）中。

/* 为什么需要模板？
想象一下，你需要写一个函数来交换两个整数的值，然后你又需要交换两个浮点数，再后来需要交换两个字符串，\
甚至自定义类型（如 Person 对象）。如果没有模板，你可能会这样做：
    函数重载： 为每种类型写一个几乎相同代码的函数。问题： 代码重复严重！维护困难！添加新类型需要写新函数。
    宏： 使用宏来实现“通用”代码。问题： 类型不安全，没有作用域，调试困难，容易出错。

为了解决代码复用和类型安全的问题，C++ 引入了模板。模板允许你编写与数据类型无关的代码蓝图（Blueprint）。 \
编译器会根据你在使用模板时提供的具体类型（或值），自动生成针对该特定类型（或值）的代码。

模板是泛型编程的基础，是C++标准模板库(STL)的基础。
*/

// 模板主要分为两类：函数模板 (Function Templates),类模板 (Class Templates):

#include <iostream>
using namespace std;

// 函数模板：定义一个可以处理多种数据类型的函数家族
// 模板声明：template <typename T, ...>
template <typename T> // 或 template <class T> ，typename 和 class 在模板声明中是等价的。
/* 注意区分typename和typedef：
typename 主要用于告诉编译器某个嵌套依赖名称（nested dependent name）是一个类型，尤其是在模板编程中。
typedef 用于为现有类型创建别名，简化复杂类型的使用。*/
// 模板参数列表的作用域仅限于紧跟其后的函数或类。每个模板声明都是独立的，不能被其他函数或类复用。
void swap_var(T &a, T &b) // 模板函数
{
    T temp = a;
    a = b;
    b = temp;
}

namespace MyFunc {
    // C++ 标准库已经提供了 std::max 函数模板。\
    如果你的代码中包含 <algorithm> 头文件，直接定义 max 会导致命名冲突。\
    可以将函数名改为 my_max 等避免冲突的名称，或者限定作用域，将函数放在命名空间中。

    template <class T, class S> // typename 和 class 在模板声明中是等价的。
    // 如果两个参数是不同类型，可以声明两个不同的模板参数
    T max(T a, S b)
    {
        return (a > b) ? a : b;
    }
}

// 类模板允许你定义一个通用类，它的成员变量和成员函数可以使用泛型类型。
template <typename T>
class MyVector // 模板类
{
private:
    T* data;
    size_t size;
public:
    MyVector(size_t n) : size(n), data(new T[n]) {}
    ~MyVector() { delete[] data; }
    
    // 重载[]下标运算符
    T& operator[](size_t i) { return data[i]; }

    // 当对象被声明为const时，编译器要求只能调用其常量成员函数（即被const修饰的成员函数）。
    const T& operator[](size_t i) const { return data[i]; } // const函数，返回const T&
};
// 类模板的成员函数通常在类内声明、类外定义（尤其是长函数体），且定义时需重复模板声明。
// 类模板实例化时必须显式指定类型（如 Vector<int>）。函数模板可以隐式实例化。
// 模板本身不是代码，而是代码生成器。编译器在看到模板定义时不会立即生成代码，\
而是在实例化（如 Vector<int>）时才根据具体类型生成对应的代码。

#endif