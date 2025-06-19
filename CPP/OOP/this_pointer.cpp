// this 指针是一个隐式的常量指针（this 本身不能被修改），它存在于类的每个非静态成员函数（如方法）中。\
简单来说，this 指向调用当前方法的对象本身。

// this 指针是系统自动生成的，且隐藏的
// this 指针不是对象的一部分，作用域在类内部
// 类的普通函数访问类的普通成员时，this 指针总是指向调用者对象

/*
类型：this 是一个隐式的常量指针，其类型由成员函数的修饰符决定：
    非 const 成员函数中：ClassName* const（指针本身不可修改，但可修改指向的对象）。
    const 成员函数中：const ClassName* const（既不可修改指针，也不可通过指针修改对象）。
值：this 存储当前对象的内存地址，即对象在堆或栈中的起始位置
this 指针通常通过寄存器（如 ECX）或函数参数栈传递给成员函数，而非作为对象的成员存储在对象内部。
*/

#include <iostream>

using namespace std;


class MyClass
{
private:
    int num = 1;
public:
    void setNum(int num)  // 如果传入的形式参数和成员变量同名
    {
        // 当参数名与成员变量名冲突时，必须使用 this 显式指定成员变量：
        num = num;  // 这两个num都是成员变量num，而不是传入参数num
        // 使用方法类似于结构指针访问结构成员，等价于(*this).num
        this->num = num;  // 使用this关键字，可以指定变量为对象的成员变量,另外一个num则是参数
        
        this->getNum();
        (*this).num;
    }

    int getNum()
    {
        return num;
    }
};

// 返回当前对象的引用,实现链式调用（如流操作符、容器操作）
class Vector 
{    
public:
    double x = 1, y = 1;
    Vector& add(const Vector& v) {
        x += v.x;
        y += v.y;
        return *this;  // 返回当前对象的引用
    }
};

// 在成员函数中获取对象地址,用于对象标识、哈希计算或内存管理
class Widget {
public:
    void* getAddress() {
        return this;  // 返回对象的内存地址
    }
};

// 实现对象的自我复制/移动，在拷贝构造函数和赋值运算符中使用
class Resource {
    int* data;
public:
    Resource& operator=(const Resource& other) {
        if (this != &other) {  // 防止自赋值
            delete[] data;
            data = new int[*other.data];
        }
        return *this;
    }
};


int main(void)
{
    MyClass obj1;
    obj1.setNum(10);

    cout << "Num = " << obj1.getNum() << endl;

    // 链式调用
    Vector v, a, b, c;
    v.add(a).add(b).add(c);
    cout << "v.x = " << v.x << ", v.y = " << v.y << endl;

    // 获取对象的内存地址
    cout << &obj1 << endl;
    Widget obj2;
    cout << &obj2 << endl;
    cout << obj2.getAddress() << endl;

    return 0;
}