#include <iostream>

// 使用memset需要包含以下头文件
// #include <string.h>  // C语言
#include <cstring>   // C++

#define LOG(x) std::cout << x << std::endl;

int main(void)
{
    void* ptr1 = 0;  // 空指针
    void* ptr2 = NULL;  // NULL本质是一个宏，被定义为0，可能导致函数重载歧义；
    void* ptr3 = nullptr;  // nullptr是 C++11 引入的关键字，类型为 std::nullptr_t，专门用于表示空指针。
    // 优先使用 nullptr：在现代 C++ 中，nullptr 完全替代 NULL，避免类型安全问题。

    int n = 10;
    // void* ptr = &n;  // 指针本质上是存储某段内存地址的变量
    int* ptr = &n;  // 给指针指定类型，以便于知道解引后赋值时往这段内存的填入什么数据是什么类型
    *ptr = 13;  // *ptr 解引
    LOG(n)

    char* buffer = new char[8];
    memset(buffer, 0 , 8);
    delete[] buffer;

    std::cin.get();
    return 0;
}