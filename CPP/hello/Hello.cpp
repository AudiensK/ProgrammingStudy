#include <iostream>

// using namespace std;
void message(const char* message);

int main()
{
    // cout << "Hello World!" << endl;
    std::cout << "Hello World!" << std::endl;  // << 是重载运算符，在这里被重载为输出运算符；
    std::cout << "Hello CPP!" << std::endl;  // endl表示跳到下一行

    // message("Hello!");

    std::cin.get();  // 在按下Enter之前会暂停，相当于system("pause")
    // system("pause");

    return 0;  // main等入口函数比较特殊，不一定要有返回值，会默认返回0
}  
// #include "EndBrace.h"  // 可以定义EndBrace.h的头文件，在里面只放一个 } ，\
再include该头文件来代替花括号，编译和运行不会出错\
由此可以知道，头文件在预编译时相当于复制粘贴

// 编译命令： g++ Hello.cpp Hello_message.cpp -o Hello