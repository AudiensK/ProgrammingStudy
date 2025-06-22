// 类的继承与派生是面向对象编程的重要特性，\
它允许创建一个新类（派生类）来继承另一个已有类（基类）的属性和方法。

// 继承(Inheritance)和派生(Derive)，是同一概念的两种不同角度的说法，\
子类（派生类\derived class）继承父类（基类\base class），父类派生子类

#include <iostream>
#include <string>
using std::cout, std::cin, std::endl, std::string;

// 父类
class Animals
{
private:
    // 该变量在基类是private，所以子类无法直接访问
    int layer;

    static string feature1;

public:
    Animals(string name) : objname(name), layer(0) {
        cout << "构造 " << objname << endl; 
    }
    ~Animals() {
        cout << "清理 " << objname << " 的资源" << endl;
    }

    void logsizeofclass()
    {
        cout << "sizeof(Aninmals) = " << sizeof(Animals) << endl;
    }

    void show_layer()
    {
        cout << objname << "的层级为" << this->layer << endl;
    }

    static void showfeature1()
    {
        cout << "feature1" << feature1 << endl;
    }

    int value1 = 1;
    int value2 = 1;
    static string feature3;

protected:
    string objname;

    static string feature2;

    enum MoveMode {
        WALK,
        RUN,
        CLIMB,
        FLY,
        SWIM
    };

    string MoveBy[3] = {
        "LIMB",
        "WING",
        "FIN"
    };

};

// 外部定义静态成员
string Animals::feature1  = "从食物摄取营养";
string Animals::feature2  = "可以活动";
string Animals::feature3  = "不可光合作用";


// 子类
// 语法： class 子类名 ： 继承权限 父类1名, 继承权限 父类2名 {}; 
// 继承权限：  继承是继承父类所有的成员，权限只是限制访问。\
    public：基类的 public 和 protected 成员在派生类中保持原有访问级别。\
    protected：基类的 public 和 protected 成员在派生类中变为 protected 成员。\
    private（默认）：基类的所有成员在派生类中变为 private 成员。
// 派生类不能直接访问基类的私有成员，只能通过基类提供的 public 或 protected 接口间接访问
class Mammals : public Animals
// public继承，保持继承自父类的所有成员的访问权限不变，基类的private成员不可直接访问
{
private:
    // 子类默认访问的是子类的同名成员
    int layer;  
public:
    // 派生类不继承基类的构造函数（和赋值运算符）。派生类的构造函数必须负责初始化它的直接基类以及自己的成员。\
        使用初始化列表调用基类构造函数：DerivedClass(...) : BaseClass(...), own_member(...) { ... }\
        如果派生类构造函数没有显式调用基类构造函数，编译器会尝试调用基类的默认构造函数。如果基类没有默认构造函数，则编译错误。
    Mammals() : Animals("Default"), layer(1) {
        cout << "构造 " << objname << endl;
    }
    
    Mammals(string name) : Animals(name), layer(1) {
        // 子类可以在内部访问父类protected成员
        cout << "构造 " << objname << endl; 

        // 子类无法直接访问父类的private成员
        // cout << value2;
    }

    // 派生类的析构函数负责清理自己新增的资源。当派生类对象被销毁时：\
        先执行派生类自己的析构函数体。\
        然后编译器自动调用其成员对象的析构函数（按声明逆序）。\
        最后编译器自动调用其直接基类的析构函数（沿着继承链向上回溯）。
    ~Mammals() {
        cout << "\n清理 " << objname << " 的新增资源" << endl;
    }

    // 函数重写，此时基类同名函数被隐藏，子类对象需要作用域符才能访问基类同名函数
    void logsizeofclass()
    {
        cout << "sizeof(Mammals) = " << sizeof(Mammals) << endl;
    }

    void logfeature()
    {
        // 静态成员访问权限和继承权限同普通成员
        // cout << Animals::feature1; // 子类不直接可访问父类private成员

        // 基类和派生类共享静态成员
        cout << "Mammals::feature2" << Mammals::feature2 << endl; // 子类可以直接访问父类protected成员
        cout << "Animals::feature2" << Animals::feature2 << endl; // 通过父类访问静态成员
    }

    int value2 = 2;
    
protected:

};

// 多级继承：子类可以作为父类继续往下派生
class Human : protected Mammals
// protected继承，基类的public和protected成员访问权限变成protected，基类的private成员不可直接访问
{
private:
public:
    // 派生类未自定构造和析构函数时，和普通类一样有默认的构造析构
    // 创建对象时构造和析构会从最下级往上，不同对象析构会从最晚的到最早
    // 由于Human类没有自定构造函数，调用的是Human类默认构造，因此接下来会调用上级类的无参构造

    void logsomemember()
    {
        cout << "feature2" << feature2 << endl;
        cout << "value2 = " << value2 << endl;
    }

protected:
};

// 单继承：子类继承一个父类
class Donkey : private Mammals
// private继承，基类的public和protected成员在派生类中都变成private（相当于派生类的私有成员，可以内部访问），基类的private成员不可直接访问
{
private:
public:
protected:
};

// 同一个父类可以派生多个子类
class Horse : public Mammals
{
private:
public:
protected:
};

// 多继承：子类继承多个父类（注意：会导致菱形继承问题）
class Mule : public Donkey, public Horse
{
private:
public:
protected:
};

int main(void)
{
    Animals a_animal("一只动物");
    Mammals a_mammal("一只哺乳动物");

    a_animal.logsizeofclass();
    // 子类对象访问重写函数
    a_mammal.logsizeofclass();
    // 子类对象通过作用域符访问重写函数的父类同名函数
    a_mammal.Animals::logsizeofclass();
    // show_layer是子类继承父类的函数，因此访问的layer也是父类的layer
    a_mammal.show_layer();

    // 子类可以在外部访问父类public成员
    cout << "a_mammal.value1 = " << a_mammal.value1 << endl;
    a_mammal.value1 = 2;
    cout << "a_mammal.value1 = " << a_mammal.value1 << endl;

    // 子类如果有与父类同名的变量成员，直接访问优先访问子类的成员
    cout << "a_mammal.value2 = " << a_mammal.value2 << endl;
    // 可以通过类名加作用域符指定访问父类的同名成员
    cout << "a_mammal.Animals::value2 = " << a_mammal.Animals::value2 << endl;

    // 基类和派生类共享静态成员
    a_mammal.logfeature();
    // 可在外部直接访问静态public成员
    cout << "Mammals::feature3" << Mammals::feature3 << endl;
    // 共享静态函数
    Animals::showfeature1();
    Mammals::showfeature1();

    // 多级继承
    // Human a_man(); // 会造成歧义，被编译器理解为无参函数
    Human a_man; // 创建对象调用无参构造，不需要圆括号
    a_man.logsomemember();

    return 0;
}

