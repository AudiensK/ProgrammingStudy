// 在 C++ 里，友元（friend）是一种特殊的机制，\
它能让类外部的函数或者其他类访问该类的私有（private）和保护（protected）成员。\
这种机制突破了类的封装性，不过在特定情形下非常实用。

// 友元分为友元函数和友元类，友元类可以创建友元对象

/*
优点：
    能够提高不同类或函数之间的数据共享效率。
    可以简化运算符重载等操作。
    在进行单元测试时，便于访问私有成员。
缺点：
    破坏了类的封装性，降低了代码的可维护性。
    过度使用友元会使代码的耦合度增加。
使用建议
    友元机制应该谨慎使用，尽量遵循类的封装原则。
    优先考虑使用公有接口（public methods），友元只是一种辅助手段。
    当需要多个类紧密协作时，可以考虑使用友元关系。
*/

#include <iostream>

class Aclass;  // 向前声明Aclass类

class Bclass
{
    int num = 3;
    
public:

    // 友元成员函数要放在后面实现，因为这里传入了Aclass的对象的引用作为参数，而此时Aclass还未完整定义
    int getAclassPrivate(Aclass &obj);
    // {
    //     obj.setVal(this->num);
    //     return obj.num;
    // }
};

class Aclass
{
private:
    int num;

public:
    // 声明友元关系
    // AsFriendFunction是Aclass的友元函数
    friend int AsFriendFunction(Aclass &obj);

    // AsFriendClass是Aclass的友元类
    friend class AsFriendClass;
    // 在C++中，这种形式的友元声明本身就会引入AsFriendClass作为类名，不需要额外的前向声明。

    // Bclass类的成员函数getAclassPrivate是Aclass的友元函数
    friend int Bclass::getAclassPrivate(Aclass &obj);
    // 由于声明友元成员函数时，Bclass类还未完整定义，无法获取Bclass的成员，因此需要在Aclass之前定义Bclass类

    void setVal(int num)
    {
        this->num = num;
    }

    // 友元是单向的，Aclass不是AsFriendClass友元类
    // void setAsFriendClassPrivate(AsFriendClass obj)
    // {
    //     // obj.num = 3; // 无法访问AsFriendClass类对象的私有成员
    // }
};

// 友元对象
class AsFriendClass
{
    int num = 2;

public:
    int getAclassPrivate(Aclass &obj) // 传入的是obj的引用
    {
        obj.setVal(this->num);
        return obj.num;
    }
};

// 友元函数
// int AsFriendFunction(Aclass obj) // 传入的是obj的拷贝
int AsFriendFunction(Aclass &obj) // 传入的是obj的引用
{
    return obj.num;
}

// 友元成员函数必须放在后面实现
int Bclass::getAclassPrivate(Aclass &obj)
    {
        obj.setVal(this->num);
        return obj.num;
    }


int main(void)
{
    Aclass obj1;
    obj1.setVal(1);
    // 通过友元函数访问对象obj1的私有成员
    std::cout << AsFriendFunction(obj1) << std::endl;

    // 创建友元对象
    AsFriendClass obj2;
    // 通过友元对象的成员函数访问对象obj1的成员
    std::cout << obj2.getAclassPrivate(obj1) << std::endl;
    std::cout << AsFriendFunction(obj1) << std::endl;

    return 0;
}