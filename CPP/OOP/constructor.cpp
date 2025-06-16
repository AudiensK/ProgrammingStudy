// 构造函数与析构函数
// 在 C++ 中，构造函数和析构函数是类的特殊成员函数，用于对象的生命周期管理。

#include <iostream>
#define OBJ(i) cout << i << endl;
using namespace std;


class MyClass1 
{
    int a;
    float b;
    // 如果有常量和引用成员，就必须在初始化
    const int id = 0;  // 可以定义常量时初始化，也可以在构造函数初始化列表中赋值

public:
    // 构造函数  
    // 构造函数通常为public，但也可以是private或protected：
        // private 构造函数：禁止外部直接创建对象（常用于单例模式）。
        // protected 构造函数：允许子类调用，但禁止外部直接创建对象。

    // 如果类中没有定义任何构造函数，编译器会自动生成一个默认构造函数（无参数，函数体为空）。
    // MyClass1() {}

    // 可以自己创建构造函数，会替代默认的构造函数
    // 构造函数没有返回值，函数名同类名，可以传入参数
    MyClass1() {
        // 可以在构造函数中执行某些程序、赋值
        cout << "   调用MyClass1()" << endl;  
        int a = 11;
        cout << "   a = " << a << endl;
    }

    // 构造函数可以重载，可以设置默认参数
    MyClass1(int _a, float _b = 3.14f) {
        cout << "   调用MyClass1(int _a, float _b = 3.14f)" << endl;
        a = _a; b = _b;
        // id = _a;  // 常量不能在函数内部赋值，只能在初始化列表或定义常量时赋值
        cout << "   a = " << a << ",b = " << b << endl;
    }

    // 其他成员
    int num;
};

class MyClass2
{
    int a;
    float b;
    // 常量和引用必须初始化
    const int id;
    const string name;

public:
    // 构造函数
    // 主构造函数
    MyClass2(const int _id, const string& _name, int _a, int _num) 
        : id(_id), name(_name), a(_a), num(_num)
    {
        cout << "   调用MyClass2(int _id, const string _name, int _a, int _num)\ 
        \n\t: id(_id), name(name), a(_a), num(_num)" << endl;
        cout << "   id=" << id << ",name is " << name << "\n    a = " << a << ",num = " << num << endl;
    }

    // 委托构造函数（Delegating Constructor）是C++11引入的一项特性，\
    允许一个构造函数调用同一个类的其他构造函数，从而避免代码重复。\
    这使得构造函数之间可以复用逻辑，提高代码的可维护性。
    MyClass2() : MyClass2(0, "Default", 0 ,0) {}

    // 另一个委托构造函数
    MyClass2(int _id) : MyClass2(_id, "unnamed", 0, 0) {}

    // 其他成员
    int num;
};

class MyClass3
{
    int& ref;
    const int id;
    int a;

public:
    MyClass3() : id(9), ref(a), a(10) 
    {
        cout << "id = " << id << ",ref = " << ref << ",a = " << a << endl;
    }

    MyClass3(int& _ref) : id(9), ref(_ref), a(10) 
    {
        cout << "id = " << id << ",ref = " << ref << ",a = " << a << endl;
        _ref = 7;  // _ref是对传入参数的引用，ref(_ref)将引用成员ref初始化为_ref
    }

    void setVal(int a)
    {
        ref = a;  // 对ref的修改就是对外部传入的引用变量的修改
    }

};


int main()
{
    // 创建对象时自动调用构造函数
    OBJ("obj1")
    MyClass1 obj1;  // 如果没有参数，就不需要加括号
    // 不能通过对象去调用构造函数，只能在创建对象时自动调用
    // obj1.MyClass1();  

    // 加括号会被解读成函数声明，代表着有一个名为obj2的函数，不接收任何参数，返回类型为MyClass1。
    OBJ("obj2")
    MyClass1 obj2();  // 这是一个函数声明而不是创建对象

    // 创建对象时后面加括号传入参数到构造函数
    OBJ("obj3")
    MyClass1 obj3(3);
    OBJ("obj4")
    MyClass1 obj4(3, 1.1f);

    // 使用构造函数初始化成员数据
    OBJ("obj5")
    MyClass2 obj5(5, "obj5", 1, 2);
    // 使用委托构造函数
    OBJ("obj6")
    MyClass2 obj6;
    OBJ("obj7")
    MyClass2 obj7(7);

    // 创建对象指针也会调用构造函数
    OBJ("op1")
    MyClass1 *op1 = new MyClass1; 
    OBJ("op2")
    MyClass1 *op2 = new MyClass1(3);
    OBJ("op3")
    MyClass2 *op3 = new MyClass2(5, "op3", 1, 2);

    // delete op1, op2, op3;  // 等同(delete op1), op2, op3;仅释放op1，op2和op3不会被释放！
    delete op1; op1 = nullptr;
    delete op2; op2 = nullptr;
    delete op3; op3 = nullptr;

    OBJ("obj8")
    int ref_out = 8;
    MyClass3 obj8(ref_out);  // obj8中的引用成员ref是对ref_out的引用
    cout << ref_out << endl;  
    obj8.setVal(6);
    cout << ref_out << endl;
    OBJ("obj9")
    MyClass3 obj9;

    return 0;
}