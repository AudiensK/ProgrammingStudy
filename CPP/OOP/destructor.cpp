// 在 C++ 中，析构函数是一种特殊的成员函数，用于在对象生命周期结束时自动释放资源。
/* 基本概念
作用：清理对象占用的资源（如动态内存、文件句柄、网络连接等），防止内存泄漏。
命名规则：析构函数名与类名相同，但前面加波浪号 ~，且不返回任何值，也不带参数。
调用时机：
    对象超出作用域时（栈对象）。
    使用 delete 释放动态分配的对象（堆对象）。
    临时对象的生命周期结束时。
    程序结束时（全局 / 静态对象）。
*/
/* 析构函数的特点
不能重载：每个类只能有一个析构函数。
不能显式调用：通常由编译器自动调用，但可通过 obj.~ClassName() 手动调用（极少见）。
默认生成：若未定义析构函数，编译器会生成一个空的默认析构函数。
虚析构函数：当基类指针指向派生类对象时，为确保正确释放派生类资源，基类析构函数必须声明为 virtual。
*/
/* 何时需要自定义析构函数？
当类管理动态资源（如 new 分配的内存、文件句柄、网络连接等）时，必须自定义析构函数释放资源。
若类包含其他资源管理对象（如智能指针），通常无需自定义析构函数。
*/
/*析构函数是 C++ 中资源获取即初始化（RAII） 原则的核心：
通过构造函数获取资源，通过析构函数释放资源，确保资源管理与对象生命周期绑定。
*/
/* 注意事项
异常安全：析构函数中应避免抛出异常（除非能确保异常被捕获），否则可能导致程序崩溃。
基类析构函数必须为虚函数：防止通过基类指针删除派生类对象时产生内存泄漏。
浅拷贝问题：若类包含指针成员，需自定义拷贝构造函数和赋值运算符，避免多个对象析构同一资源（见深拷贝）。
*/

#include <iostream>
using namespace std;

class FileHandler {
private:
    FILE* file;
    int* data = new int[10];  // 可以在定义时分配内存
    int* data1{new int[10]};  // C++11后的初始化方式
    int* data2;  // 也可以先声明，然后在构造函数中分配内存

public:
    // 构造函数
    FileHandler(const char* filename) {
        file = fopen(filename, "w");  // 获取资源
        data2 = new int[10];
    }

    // 析构函数
    // 编译器会默认生成一个空的析构函数，手动设置的析构函数会取代默认的析构函数，
    // 析构函数没有返回值和参数，不能重载，一个类只能有一个析构函数
    // 析构函数通常是public，但也可以是private和protected
    // 析构函数会在对象生命周期结束时自动调用，也可以obj.~ClassName() 
    ~FileHandler();

    // 写入文件
    void write(const char* content);
};

FileHandler::~FileHandler() // 析构函数也可以在类里面生命，外部实现
{
    if (file) fclose(file);  // 释放资源
    if (data) delete data; data = nullptr;  // 清理内存，空置指针
    if (data1) delete data1; data1 = nullptr;
    if (data2) delete data2; data2 = nullptr;
}

void FileHandler::write(const char* content)
{
    fprintf(file, content);
}


int main(void)
{
    const char* content = "abc123一二三";  // 必须使用const，非const有可能通过这个指针修改常量导致未定义行为
    char filename[10] = "text.txt";  // 字符串数组不用const，初始化是将常量复制到数组中
    
    FileHandler text(filename);
    text.write(content); 

    text.~FileHandler();  // 可以手动调用析构函数
    // 调用析构函数不等于对象生命周期结束，但是对象生命周期结束会自动调用析构函数

    return 0;
}
