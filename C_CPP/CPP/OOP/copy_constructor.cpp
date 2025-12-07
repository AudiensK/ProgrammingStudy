// C++ 的拷贝构造函数是一种特殊的构造函数，用于创建一个新对象，该对象是已有对象的副本。

#include <iostream>
using std::cout, std::cin, std::endl;

class MyClass
{
    int a = 1;
    int* data;
public:
    MyClass()  // 在调用拷贝构造函数后，其他构造函数不会被调用
    // 因为拷贝函数本质仍然是构造函数，只不过其传入参数是对同类对象的引用
    {
        data = new int(0);
    }

    ~MyClass()
    {
        delete data;
    }

    // 拷贝构造函数的参数是对同类对象的引用（通常用const修饰以防止修改原对象）
    MyClass(const MyClass& obj) 
    {
        // 手动复制obj的成员到当前对象
        a = obj.a;
        // 拷贝构造函数的主要任务是复制对象的成员变量（即对象的状态）
        // 类中的函数是类的定义，不是对象的状态，不需要手动拷贝

        // 浅拷贝 vs 深拷贝
        // 浅拷贝：仅复制成员变量的值。如果成员包含指针，只复制指针值（即指向同一块内存），\
        可能导致内存泄漏或悬垂指针问题（例如原对象和副本析构时重复释放内存）。
        b = obj.b;  // 复制指针的值

        // 浅拷贝容易出现的问题
        // data = obj.data;  
        // data所指的内存地址丢失，无法释放内存，导致内存泄漏；\
        两个对象析构时，释放同一块内存，可能导致崩溃

        // 深拷贝：自定义拷贝构造函数，为指针成员分配新内存并复制内容，确保每个对象有独立的资源。
        *c = *obj.c;  // 指针c已经默认初始化指向a了，因此只需要复制变量的值
        // 如果指针c是在普通构造函数中初始化的，在拷贝构造函数中仍需要初始化，因为创建对象只会调用一个构造函数
        // 深拷贝，分配新的内存，复制值
        data = new int(*obj.data);

    }

    // 拷贝构造函数可以重载，且应当使用初始化列表来初始化成员变量
    MyClass(const MyClass& obj, int n):
        a(obj.a),
        b(obj.b), // 浅拷贝，复制值
        data(new int(*obj.data))  // 深拷贝，分配新的内存，复制值
    {
        // 定义一个空拷贝构造函数，新对象的成员的值是默认值
        // *c = *obj.c;  // 指针c已经默认初始化指向a了，因此只需要复制变量的值
    }  

    int* b = &a;
    int* c = &a;
    
};

class MyClass1
{
public:
    int b = 2;
    int& a = b;
    MyClass1() = default;  // 显式声明默认构造函数

    // 未自定拷贝函数时，编译器会自动生成一个浅拷贝的默认拷贝构造函数。它会逐位复制对象的所有成员变量。

    MyClass1(const MyClass1& obj) = default;  // 显式声明默认拷贝构造函数
};

class MyClass2
{
public:
    MyClass2() = default;  // 显式声明默认构造函数

    // 如果不希望对象被拷贝（例如管理独占资源的类），\
    可以将拷贝构造函数声明为private或使用= delete（C++11 及以后），\
    也可以声明一个空的私有拷贝构造函数，不对其进行定义
    MyClass2(const MyClass2&) = delete;
    // 禁止复制时，必须显示声明默认构造函数，否则可能导致隐式默认构造函数被抑制、对象无法无参构造
};

// 函数返回对象时可能拷贝
MyClass1 createObj() {
    MyClass1 temp;
    return temp; // 返回时可能拷贝（现代编译器可能优化）
}

// 对象作为参数传入函数时拷贝
void use_obj(MyClass1 obj)
{
    cout << obj.b;
    obj.b = 5;
    cout << obj.b;
}


int main(void)
{
    // 调用拷贝函数
    MyClass1 obj1;
    // 对象初始化时拷贝
    MyClass1 obj2(obj1); // 显式调用
    MyClass1 obj3 = obj1; // 隐式调用
    cout << obj1.b << obj2.b << obj3.b << endl;
    // 调用拷贝函数生成的对象不是原对象的引用，而是复制生成了一个新的对象
    obj1.b = 3; obj3.b = 4;
    cout << obj1.b << obj2.b << obj3.b << endl;
    // 默认拷贝函数为浅拷贝，因此obj2.a，obj3.a都是对obj1.b的引用
    obj1.a = 1; cout << obj1.a << obj1.b << obj2.b << obj3.b << endl;
    obj2.a = 2; cout << obj1.a << obj1.b << obj2.b << obj3.b << endl;
    obj3.a = 3; cout << obj1.a << obj1.b << obj2.b << obj3.b << endl;

    // 对象作为值参数传入函数。
    use_obj(obj1);  // 传递时拷贝
    // 函数内的对象是传入的对象拷贝，类似于传入变量
    cout << obj1.b << endl;
    

    return 0;
}