// 在 C++ 里，new和delete是用于管理堆内存的两个重要操作符
// new和delete是可重载的运算符，malloc和free是函数

#include <iostream>
#include <cstring>
using std::cout, std::cin, std::endl;

class Person {
    public:
    void print(void) {
        std::cout << "Person" << std::endl;
    }
};

int main()
{
    // new操作符的作用是在堆上动态地分配内存，并且会自动调用对象的构造函数。

    // 为单个对象分配内存
    int* ptr1 = new int;  // 分配一个int类型大小的内存空间
    *ptr1 = 0;
    Person* p = new Person();  // 分配一个Person对象的内存空间，并调用默认构造函数
    (*p).print();
    p->print();

    // 申请单个内存并初始化
    int* ptr2 = new int(123);  // 分配一个int类型大小的内存空间，并初始化为123
    cout << "*ptr2=" << *ptr2 << endl;

    // 批量申请（连续的内存）
    int* arr = new int[10];  // 分配一个包含10个int元素的数组内存空间
    char* str = new char[20];  // 分配一个能存储20个字符的字符串内存空间
    for (size_t i = 0; i < 10; i++)
    {
        arr[i] = i;
        cout << "p3[" << i << "] = " << arr[i] << endl;
    }

    // *str = "Hello";  // *str 是解引用操作，它访问的是 str 指向的第一个字符（即内存地址 str 处的值）
    strncpy(str, "Hello", 19);  // 将"Hello"及其结束符'\0'复制到str指向的内存，最多复制19个字符
    str[19] = '\0';  // 手动添加结束符，防止溢出
    // 或者使用循环逐个字符赋值
    // 或者使用snprintf（最安全），会自动处理字符串长度，避免溢出：
    snprintf(str, 20, "Hello, World!");  // 自动截断多余字符，确保不超过19个有效字符+1个结束符
    cout << str << endl;

    // delete操作符的作用是释放new分配的堆内存，并且会自动调用对象的析构函数。

    delete ptr1;  // 释放单个内存，每个new都必须对应一次delete，以防内存泄漏
    // delete ptr1;  // 禁止重复释放
    ptr2 = nullptr;  // 在释放内存之后，要将指针设置为nullptr，防止出现野指针。

    delete ptr2;
    ptr2 = nullptr;  // 空置释放后的指针
    delete ptr2;  // 再次delete该指针就不会报错

    delete p;
    p = nullptr;

    // 定位 new（Placement New）,允许你在已经分配好的内存上构造对象。
    void* buffer = malloc(sizeof(Person));  // 用malloc分配一块原始内存
    Person* p2 = new(buffer) Person();        // 在buffer这块内存上构造Person对象
    p2->~Person();       // 显式调用析构函数，销毁对象
    free(buffer);       // 释放malloc分配的内存

    // 释放连续内存
    delete[] arr;  // 释放arr所指向的int数组的内存
    delete[] str;  // 释放str所指向的字符数组的内存    

    cin.get();
    return 0;
}