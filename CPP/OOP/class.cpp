// 类是一种用户自定义的数据类型（函数，数据），可以看作结构体struct的升级版
// 类是具有相同的属性（数据）和行为（函数）的对象的集合
// 类是对象的抽象，对象是类的具体
// 对象：通过使用类类型定义的变量

/*
类的定义 = 数据结构 + 函数集合
类的成员变量会被组织成一个类似结构体（struct）的数据结构，占用连续的内存空间，
创建对象时，各个对象的拥有独立的成员变量
而类的成员函数（方法）不会存储在每个对象中，而是被编译为独立的函数，存储在代码段中。
所有对象共享同一套成员函数（方法）。
*/

#include <iostream>
#include <cstring>

// 定义类
class Class_name  // class 类名
{
// 默认是私有的
    // 成员：1 数据 2 函数

// 访问权限修饰关键字
public:  // 公有的，外部可调用
    // 成员：1 数据 2 函数

private:  // 私有的，当前类可以访问
    // 成员：1 数据 2 函数

protected:  // 被保护的，当前类及子类可以访问
    // 成员：1 数据 2 函数

};  // 定义需要分号结尾

class Sheep
{
    int age;
public:
    char name[10];

    // 默认构造函数
    Sheep() : name("羊"), age(0) {}  


    // 成员函数
    void eat()
    {
        std::cout << name << "正在吃草" << std::endl;
    }

    void set_age(int _age)  // 可以在定义一个公有函数访问私有的数据
    {
        age = _age;
    }

    int show_age(void)
    {
        std::cout << "年龄：" << age << std::endl;
        return age;
    }

private:
    void show_info(void);  // 函数可以在类里面声明，在外部实现

protected:
    int gender = 0;

};

// C++中也可以用struct定义类，但是C中是非法的
struct Class {
    int a = 0;  // 默认公有的
public:
    void log() {
        std::cout << "Class" << std::endl;
    }
};


int main()
{
    // 定义对象
    Sheep asheep;
    // asheep.name = "Nill";  // 
    strcpy(asheep.name, "小羊");
    asheep.eat();
    // asheep.age = 1;  // 私有数据无法直接访问
    // 可通过公有的函数访问私有数据
    asheep.set_age(1);
    int a_age = asheep.show_age();  

    // 定义对象指针
    Sheep *another_sheep = new Sheep;
    strcpy(another_sheep->name, "大羊");
    another_sheep->eat();
    delete another_sheep;

    return 0;
}

void Sheep::show_info(void)  // 类名::函数名 指定函数属于某个类
{
    std::cout << "名字" << name << ", 年龄" << age << std::endl; 
}