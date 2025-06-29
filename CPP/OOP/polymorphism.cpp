// 在 C++ 里，多态是面向对象编程的重要特性，它允许不同的对象通过相同的接口来展现不同的行为。\
多态主要分为静态多态（编译时多态）和动态多态（运行时多态）

// 在 C++ 中，联编（Binding）是指将函数调用与相应的函数定义（代码）关联起来的过程。\
根据联编发生的时机，可分为静态联编（早期联编）和动态联编（晚期联编）。

// 静态联编（Static Binding）\
    定义：在编译阶段确定函数调用的具体实现。编译器根据函数调用的参数类型、函数名和上下文直接生成对应的机器码。\
    实现方式：\
        非虚函数调用\
        函数重载（根据参数类型匹配）\
        模板实例化\
    优点：执行效率高（无需运行时开销）。\
    缺点：缺乏灵活性，无法实现运行时的动态行为。

// 动态联编（Dynamic Binding）\
    定义：在运行阶段确定函数调用的具体实现。\
    通过基类指针或引用调用虚函数时，系统会根据对象的实际类型（而非指针类型）来选择正确的函数版本。\
    实现方式：\
        虚函数（virtual 关键字）\
        基类指针 / 引用指向派生类对象\
    核心机制：虚函数表（vtable）和虚表指针（vptr）。\
        虚函数表：每个包含虚函数的类都会生成一个虚函数表，存储该类的虚函数地址。\
        虚表指针：每个对象实例都包含一个指向所属类虚函数表的指针（vptr），用于在运行时查找函数地址。\
    优点：实现多态性，代码更灵活、可扩展。\
    缺点：额外内存开销（每个对象需存储 vptr，每个类需维护 vtable）。\
        运行时查找虚函数表会降低性能。

// 多态和联编示例
#include <iostream>

// 动态多态基于继承和虚函数来实现，在运行时才会确定要调用的函数。
// 虚函数
class Animal {
public:
    virtual void speak() const {  // 虚函数
        std::cout << "Animal speaks" << std::endl;
    }

    void showclass() {
        std::cout << "Animal" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() const override {  // 重写虚函数
        std::cout << "Dog barks" << std::endl;
    }

    void showclass() {
        std::cout << "Animal" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {  // 重写虚函数
        std::cout << "Cat meows" << std::endl;
    }

    void showclass() {
        std::cout << "Animal" << std::endl;
    }
};

// 静态多态依靠函数重载和模板（泛型编程）来实现，在编译阶段就会确定要调用的函数。
// 函数重载
void print(int num) {
    std::cout << "整数: " << num << std::endl;
}

void print(double num) {
    std::cout << "浮点数: " << num << std::endl;
}

int main() {
    // 动态联编（虚函数）
    // 创建子类对象
    Dog dog;
    Cat cat;

    // 基类指针指向派生类对象
    int index = 1;
    Animal* animal = nullptr;
    switch (index) {
        case 0:
            animal = &dog;
            break;
        case 1:
            animal = &cat;
            break;
        default:
            animal = &dog;
            break;
    }

    // 动态多态：根据对象的实际类型调用对应的 speak() 函数
    animal->speak();
    // 根据指针本身类型调用对象的函数：\
    通过父类指针调用在父类子类中同名的普通函数，不论其指向父类还是子类对象，都会调用父类的函数
    animal->showclass();

    // 如果不使用虚函数实现多态，需要在编译前确定两个函数调用
    index = 0;
    // 通过if-else手动选择调用哪个对象的函数，而非由对象类型自动决定。
    if (index == 1) {
        cat.speak();
    } else {
        dog.speak();
    } // dog.speak()和cat.speak()都是静态调用，在编译时已确定函数地址。    
    
    
    // 静态联编
    print(10);      // 编译时确定调用 print(int)
    print(3.14);    // 编译时确定调用 print(double)

    return 0;
}