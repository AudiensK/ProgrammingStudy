// 函数参数缺省（Default Arguments）是 C++ 的一项特性，允许为函数的参数指定默认值。\
当调用函数时，如果用户没有提供对应的参数值，则使用默认值。\
这一机制可以简化函数调用，同时提供灵活的接口设计。

// 核心概念\
默认值的指定：在函数声明或定义时，使用赋值符号（=）为参数指定默认值。\
调用时可省略参数：如果用户没有提供参数，则自动使用默认值。\
从右向左连续指定：如果有多个默认参数，必须从右向左连续设置，不能间隔\

#include <stdio.h>


// void log(int a, float b = 3.14, double c = 3.1415);  // 参数默认值只能指定一次
// void log(int a = 1, float b, double c = 3.1415);  // 要从右向左连续指定默认值，中间不可间隔
// void log(int a);  // 重载可能与默认参数冲突
const int cons = 2;  // 默认值必须是编译时常量
void log(int a = cons, float b = 3.14, double c = 3.1415); 


int main(void)
{
    log(1, 1.1f, 3.1);  // 函数参数传入是从左到右传入
    // 因此默认值指定要从右到左连续指定，否则调用函数时省略参数时会发生误会
    log(1);  // 传入参数a=1，参数b、c未传入，因此为默认值
    // 重载可能与默认参数冲突  
    // 如果有一个void log(int a); log(1)调用该参数时，\
    编译器无法确定是调用void log(int a)，a传入1，\
    还是调用void log(int a, float b, double c)，a传入1，b、c为默认
    log();

    return 0;
}


// void log(int a, float b = 3.14, double c = 3.1415)  // 在声明中指定后参数默认值，在定义中就不能再次指定
void log(int a, float b, double c)
{
    printf("a=%d, b=%f, c=%lf\n", a, b, c);
}

// void log(int a)
// {
//     printf("a=%d\n", a);
// }