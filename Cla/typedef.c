#include <stdio.h>


// 声明函数原型
int plus(int a, int b, Callback call);
int callback(int a, int b);


// 可用于定义回调函数类型
typedef int (*Callback)(int a, int b);  // 定义一个名为Callback的函数指针类型，返回值int,参数int a, int b

// 可用于定义枚举类型，能简化
typedef enum {
    NO_EVENT = 0,
    LEFT_BUTTON_DOWN,
    LEFT_BUTTON_RELEASE,
    RIGHT_BUTTON,
    RIGHT_BUTTON_RELEASE,
} MOUSEEVENT;

MOUSEEVENT event1 = LEFT_BUTTON_DOWN;  // 不需要enum关键字，能够直接用类型名声明变量

// enum MOUSEEVENT {
//     NO_EVENT = 0,
//     LEFT_BUTTON_DOWN,
//     LEFT_BUTTON_RELEASE,
//     RIGHT_BUTTON,
//     RIGHT_BUTTON_RELEASE,
// };

// enum MOUSTEEVEN event1 = LEFT_BUTTON_DOWN;  // 不适用typedef，声明枚举变量需要带上enum关键字


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
    APoint cs = {3, 4};

    // typedef 字符串数组
    typedef char* String[10];  // String是10个字符串的数组的类型
    // typedef char* String[];
    String str = {"string1", "string2", "string3",};

    // 字符串变量
    char str1[10] = "string";
    char *str2 = "string";


    //回调函数
    int a=1,b=2;
    printf("a+b=%d\n", plus(a, b, callback));

    return 0;
}


int plus(int a, int b, Callback call)
{
    // 运行一些程序
    printf("do something...\n");
    // 满足条件后回调函数
    return call(a, b);
}


int callback(int a, int b)
{
    return a + b;
}