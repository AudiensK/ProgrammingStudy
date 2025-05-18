#include <stdio.h>

int main()
{
    // 自定义数据类型（typedef）
    // C语言提供了一个叫做typedef的功能来声明一个已有的数据类型的新名字。比如
    typedef int Length;
    // 使得Length成为int类型的别名。
    // 这样，Length这个名字就可以代替int出现在变量定义和参数声明的地方了：
    Length al, bl, len;
    Length number[10];

    // typedef
    // 声明新的类型的名字
    // 新的名字是某种类型的别名
    // 改善了程序的可读性
    typedef struct a_point {  // a_point是结构的名字
        int a;
        int b;
    } Point;  // Point是声明的新的类型的名字

    // 也可以省去结构名字直接声明类型的名字
    // typedef struct {
    //     int a;
    //     int b;
    // } Point;

    typedef struct a_point APoint;  // 也可以先声明一个结构，再typedef声明这个新类型的名字
    struct a_point as = {2, 3};
    Point bs = {1, 2};  // 可以简化声明结构变量的语句
    APoint cs = {};

    // typedef 字符串数组
    typedef char* String[10];  // String是10个字符串的数组的类型
    // typedef char* String[];
    String str = {"string1", "string2", "string3",};

    // 字符串变量
    char str1[10] = "string";
    char *str2 = "string";

    return 0;
}