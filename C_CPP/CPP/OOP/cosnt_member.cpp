// 在 C++ 中，类的const成员是指被声明为const的类成员变量或成员函数。

// const成员变量
// 必须初始化：const成员变量必须在对象创建时初始化，且之后不能被修改。
// 初始化方式：
// 类内初始值（C++11 起支持）：直接在成员变量声明处赋值。
// 构造函数初始化列表：在每个构造函数中显式初始化。

// const成员函数
// 不修改对象状态：const成员函数承诺不会修改对象的任何非静态成员变量。
// 语法：在函数声明和定义的参数列表后加const关键字。

#include <iostream>

using std::cout, std::cin, std::endl;

class MyClass
{

public:
    // 普通成员变量 可以不用初始化
    int num1;
    // const成员变量 必须初始化
    const int NUM2;
    const int NUM3;
    // C++11以后可以直接在声明处赋值初始化
    const int NUM4 = 4;
    // 静态const成员变量遵循static规则在类外初始化
    static const int NUM5;

    MyClass(int num) : NUM2(2), NUM3(num)
    {
        // NUM3 = 3;  // 必须在初始化列表中初始化或定义时初始化
    }

    ~MyClass() {}

    // 常量成员函数
    int getValue() const // 在函数括号后面加const
    {
        // const成员函数承诺不会修改对象的任何非静态成员变量。
        // NUM3 = 1; // const成员变量不能修改
        // num1 = 1; // 普通成员变量也无法修改
        // this->num1 = 1;
        // NUM5 = 1;  // 静态const成员无法修改
        num6 = 7;  // 静态成员变量可以修改
       
        return num6;
    }

    const int *getPtr() const;

    int NoConstantFunc()
    {
        return 1;
    }

    static int num6;

    // 突破const限制：如果需要在const成员函数中修改某个成员变量，可以将该变量声明为mutable。
    mutable int counter = 0;  // mutable成员

private:

};

// 初始化静态成员变量
const int MyClass::NUM5 = 5;
int MyClass::num6 = 6;

const int *MyClass::getPtr() const
{
    // int* p = &NUM2; // 类型不匹配
    const int* p1 = &NUM2;
    // const成员函数内部的this指针类型是const MyClass*，\
    这导致所有成员变量的访问都被视为const类型，即使成员变量本身不是const。
    const int* p2 = &num1;

    return p2;
}

int main()
{
    // 非静态const成员变量在每个对象中可以有不同的值，但必须在对象创建时确定：
    MyClass obj1(3);
    cout << "obj1.NUM3 = " << obj1.NUM3 << endl;
    // obj1.NUM3 = 4;  // 不可修改，因为是常量
    MyClass obj2(4);
    cout << "obj2.NUM3 = " << obj2.NUM3 << endl;

    // const对象
    const MyClass obj3(5);
    MyClass const obj4(6);
    // const对象只能查看成员变量，不能修改
    // obj3.num1 = 1;
    // obj3.NUM2 = 1;
    cout << "obj3.num1 = " << obj3.num1 << endl; 
    cout << "obj4.NUM2 = " << obj4.NUM2 << endl; 
    // const对象只能调用const成员函数
    obj3.~MyClass();  // const对象可以调用构造和析构
    // obj4.NoConstantFunc(); // 不能调用非const函数
    obj1.NoConstantFunc(); // 非const对象可以调用
    // 静态成员属于类而不属于单独一个对象
    cout << obj1.NUM5 << endl;
    cout << MyClass::num6 << endl;

    // cin.get();
    return 0;
}