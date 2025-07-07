#include <iostream>

// 在 C++ 中，常量对象（const 对象）是指被 const 关键字修饰的对象，\
其核心特点是状态不可被修改，这一特性贯穿于对象的生命周期和使用规则中。

// 常量对象的成员变量（除非声明为 mutable）在初始化后无法被修改。\
任何试图修改其成员的操作都会被编译器禁止。
// 常量对象只能调用类中被 const 修饰的常量成员函数（即函数声明后加 const），\
而不能调用非常量成员函数。这是为了保证对象状态不被修改。
// 常量对象必须在定义时初始化（通过构造函数），且初始化后不能被整体赋值给其他对象（但可以初始化其他对象）。
// 当指针或引用指向常量对象时，其行为也会受到限制：\
指向常量的指针（const T*）：不能通过指针修改对象，但指针本身可以指向其他对象。\
常量指针（T* const）：指针本身不能指向其他对象，但可以通过指针修改对象（如果对象本身不是常量）。
// 如果类的成员变量被 mutable 修饰，则即使在常量对象中，\
该成员也可以被修改（通常用于记录日志、缓存等不影响对象逻辑状态的场景）。

class MyClass {
public:
    int value;
    const int cvalue = 10;
    MyClass(int v) : value(v) {
        std::cout << "调用构造函数" << std::endl; 
    }
    ~MyClass() {
        value = 5;
        modify(4);
        std::cout << "调用析构函数" << std::endl;
    }

    void show() const { // 常量成员函数（不会修改对象）
        std::cout << value << std::endl;
    }

    void modify(int v) { // 非常量成员函数（可能修改对象）
        value = v;
    }
};

int main()
{
    const MyClass cobj(10);
    std::cout << cobj.cvalue << std::endl; // 正确：调用常量成员
    cobj.show(); // 正确：调用常量成员函数
    // cobj.value = 20; // 错误：无法修改常量对象的成员
    // cobj.modify(); // 错误：常量对象不能调用非常量成员函数
    cobj.~MyClass(); // 可以通过析构调用非常量成员

    return 0;
}
