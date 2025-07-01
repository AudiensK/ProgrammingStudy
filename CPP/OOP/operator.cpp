// 运算符重载（Operator Overloading）是 C++ 的核心特性之一，\
它允许我们为自定义类型（类或结构体）重新定义运算符的行为，\
使其能够像内置类型（如 int、float）一样进行直观的运算。\
语法： 返回类型 operator运算符(参数列表) { // 函数体 }

/*
可重载的运算符:
算术运算符	+, -, *, /, %, ++, --
关系运算符	==, !=, <, >, <=, >=
逻辑运算符	&&, ||, !
位运算符	&, |, ^, ~, <<, >>`
赋值运算符	=, +=, -=, *=, /=, %=
其他	[], (), ->, ,, new, delete

不可重载的运算符：::, .*, ., ?:, sizeof
*/

// 运算符函数既可以作为类的成员函数，也可以作为非成员函数（通常是友元函数）来实现。

#include <iostream>

class ComplexNum
{
public:
    ComplexNum(double _real = 0, double _imaginary = 0) : real(_real), imaginary(_imaginary) {}
    ~ComplexNum() {}

    void logComplexNum()
    {
        std::cout << "(" << real << "+" << imaginary << "i)" << std::endl;
    }

    void operator++() // 重载一元运算符，有一个隐藏参数（this）
    {
        this->real++;
        this->imaginary++;
    }
    
    ComplexNum operator+(const ComplexNum& other) const // 重载二元运算符，有两个参数，包含一个隐藏的this
    {
        return ComplexNum(real + other.real, imaginary + other.imaginary);
    }

    ComplexNum& operator=(const ComplexNum& other) // 重载赋值运算符
    {
        if (this != &other) {  // 防止自赋值
            real = other.real;
            imaginary = other.imaginary;
        }
        return *this;
    }

private:
    double real, imaginary;
};

int main()
{
    ComplexNum cnum1(3.1, 4.0);
    cnum1.logComplexNum();

    ComplexNum cnum2(4, 6.6);
    cnum2.logComplexNum();

    // 重载后的+号相当于一个函数，以下写法相当于cnum1.operator+(cnum2)
    ComplexNum cnum3 = cnum1 + cnum2;
    cnum3.logComplexNum();

    cnum3 = cnum1.operator+(cnum2);
    cnum3.logComplexNum();

    cnum3 = cnum1 + cnum2 + cnum3;
    cnum3.logComplexNum();

    ++cnum3;
    // cnum3++; // 重载一元运算符只能在左边（单目运算符）
    cnum3.logComplexNum();

    cnum3 = cnum1;
    cnum3.logComplexNum();

    return 0;
}