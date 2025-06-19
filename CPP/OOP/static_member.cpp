// static成员
// 静态成员是类中特殊的成员，不依赖于类的对象实例存在，而是属于类本身。\
它有两种形式：静态成员变量和静态成员函数，二者的核心特性如下：
/*
静态成员变量：类级别的共享数据
    声明方式：在类内用static关键字声明，但必须在类外定义和初始化
    存储位置：位于程序的全局数据区（静态区），而非对象内存中
    访问方式：可通过类名::成员名或对象.成员名访问（推荐前者）
静态成员函数：无 this 指针的类操作
    无this指针：无法访问非静态成员（因为没有隐含的对象指针）
    调用方式：必须通过类名::函数名()调用，或通过对象调用（但无意义）
*/

#include <iostream>
using namespace std;

class MyClass
{
private:
    int c = 1;
public:
    MyClass()  // 普通成员可以访问静态成员
    {
        // 在类里面声明，在类外定义和初始化后，静态成员变量就可以正常使用
        num++;  // 通过静态成员变量记录对象创建数量
    }

    ~MyClass()
    {
        num--;  // 对象析构时数量减一 
    }

    // 静态成员变量不能在类里面初始化，不论是初始化列表还是构造函数内都不能初始化
    // 静态成员变量储存于全局数据区，而非对象内存中，生命周期比对象长
    // 在类内用static关键字声明，但必须在类外定义和初始化
    static int num;
    // 同类所有对象共享静态成员变量


    static int add(int a, int b);  // 静态成员函数可以在类内声明，外部定义，也可以在类内定义
    
};

// 静态成员变量必须在类外定义和初始化
// int MyClass::num;  
int MyClass::num = 0;

// 静态成员函数
// 可以作为工具函数，与类相关但不依赖对象状态的操作
int MyClass::add(int a, int b)  // 静态成员函数在外部定义时不需要static关键字
{
    
    // 静态成员函数不依赖对象存在，可以使用类名直接调用
    // 静态成员无法访问普通成员，静态成员没有 this 指针
    // c = 2;  // 不合法，因为c是普通成员变量，需要实例化对象才能调用
    num = 0;  // 合法，num是静态成员变量

    return a + b;
}

// 使用静态成员函数实现 单例Singleton
class Singleton 
{
private:
    // 声明一个该类的对象的指针，在外部初始化为NULL
    static Singleton* instance;

    Singleton() {}  // 私有构造函数，只能通过静态成员函数调用

    // 必须禁止拷贝，否则单例模式失败
    // 可通过私有拷贝构造函数实现禁止拷贝
    // Singleton(const Singleton& obj) {}  
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
        instance = new Singleton();
        }
        return instance;
    }

    // C++11以后可以使用= delete禁用拷贝
    Singleton(const Singleton&) = delete;

    ~Singleton() 
    {
        // 在单例模式中，析构函数置空指针不仅无效，还可能引发严重问题。

        // instance = nullptr;  // 错误做法

        // 当单例对象被销毁后，instance确实被置为nullptr。但此时：\
            其他代码可能持有已销毁对象的指针，继续使用会导致空指针解引用。\
            ** 再次调用getInstance()** 会创建新对象，违反单例模式 "全局唯一" 的原则。
        // 单例对象通常应在程序结束时自动销毁，无需手动管理。

        delete instance;
    }
};
// 初始化静态成员变量
Singleton* Singleton::instance = nullptr;


int main(void)
{
    MyClass obj1, obj2, obj3;
    // 可通过类名::成员名 或 对象.成员名访问（推荐前者）
    cout << "numbers of objects of MyClass: " << MyClass::num << endl;
    cout << "numbers of objects of MyClass: " << obj1.num << endl;

    int n;
    // 通过对象调用（但无意义）
    n = obj1.add(1, 1);
    n = (&obj1)->add(1, 2);
    // 无需访问对象成员，仅处理输入参数
    n = MyClass::add(1, 3);
    cout << "n = " << n << endl;
    cout << "num = " << MyClass::num << endl;

    // 单例
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    Singleton* p3 = Singleton::getInstance();
    // 可以看到三个指针都指向同一个地址/同一个对象，单例模式成功
    cout << hex << p1 << endl;  // hex 十六进制
    cout << p2 << endl;
    cout << p3 << endl;

    return 0;
}