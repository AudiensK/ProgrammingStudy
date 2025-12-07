// String是C++中的字符串，类似于C语言中的字符数组
// 其中包含许多方法，使用时需要额外包含<string>

#include <iostream>

// #include <string.h>  // 这是C的string库，.h结尾，在cpp中对应的为cstring，没有.h
// 这是Cpp的string库，没有.h结尾，基于STL容器实现。std::string类封装了动态字符数组，自动管理内存。
#include <string>

using std::cout, std::cin, std::endl, std::string;


int main()
{
    cout << sizeof(string) << endl;
    string a = "一二三四五六七八九十";
    cout << a << "=" << sizeof(a) << endl;

    // C语言风格字符串（字符数组）
    char str_old[10];  
    // str_old = "abc";  // 初始化后就不能直接赋值，必须逐字赋值或使用string.h中的字符操作函数

    // C++字符串
    string str;
    str = "abc123一二三";  // 可以直接赋值
    char chr = str[0];  // 获取字符串中单个字符
    chr = str.at(1);  // 另一种写法
    cout << chr << endl;
    int len = str.length();  // .length()获取字符串长度
    cout << len << endl;
    str.clear();  // .clear()清空字符串
    cout << str << endl;
    bool ifempty = str.empty();  // 判断字符串是否为空
    cout << ifempty << endl;
    bool ifeq = str == str;  // 直接比较字符串
    cout << ifeq << endl;

    return 0;
}

/*  总结
场景	                       选择cstring	                   选择string
与 C 代码交互                   ✅ 必须使用 C 风格字符串         ❌ 需通过c_str()转换
性能敏感的嵌入式系统             ✅ 手动内存管理更高效            ❌ 动态内存分配可能有开销
简单字符串操作                  ✅ 代码简单（如printf直接打印）  ❌ 需转换为 C 风格字符串才能用printf
复杂字符串处理（拼接、查找）     ❌ 操作繁琐且不安全              ✅ 简洁、安全且功能丰富
面向对象设计                    ❌ 缺乏类封装                   ✅ 支持 STL 容器和算法
*/