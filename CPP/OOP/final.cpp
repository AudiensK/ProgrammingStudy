// 在 C++ 里，final是 C++11 引入的一个关键字，主要有两种用途：一是禁止类被继承，二是防止虚函数被重写。

#include <iostream>

using namespace std;

class Shape
{
public:
    virtual double area() = 0;
};

class Circle : public Shape
{
public:
    Circle() : r(1.0) { cout << "default r = 1.0" << endl; }
    Circle(double _r) : r(_r) { cout << "r = " << Circle::r << endl; }
    ~Circle() {}

    // 防止虚函数被重写
    double area() final
    {
        return r * PI;
    }

private:
    double r;

protected:
    double PI = 3.1415926;
};

// 禁止类被继承
class Oval final : public Circle
{
public:
    // Oval的父类中area函数已经被标为final，无法被重写
    // double area() override {}
};

// Oval被标记为final，无法被继承
// class OtherOval : public Oval {};

int main()
{
    return 0;
}