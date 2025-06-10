// 全局变量
// 定义在函数外面的变量是全局变量
// 全局变量具有全局生存期和作用域：
//  它们与任何函数无关，在任何函数内部都可以使用它们

#include <stdio.h>

// 全局变量初始化
// 没有初始化的全局变量会得到0值
//  指针则会得到NULL值
// 只能用编译时刻已知的值来初始化全局变量
// 它们的初始化发生在main函数之前

// int gAll = 10;
int gAll;
// 必须用已知的值来初始化全局变量
// int gAll = f();  // 报错
const int g1 = 11;
// int g2 = gAll;  // 报错  
// 如果g1是const，则可以用于全局变量初始化，但是要尽量避免这种方法初始化全局变量
// int g2 = g1;

// 全局变量被隐藏
// 如果函数内部存在与全局变量同名的变量，全局变量会被隐藏

// tips
// 不要使用全局变量来在函数间传递参数和结果
// 尽量避免使用全局变量（比如丰田汽车的案例和全局变量相关）
//  *使用全局变量和静态本地变量的函数是线程不安全的


int f(void);


int main(int argc, const char *argv[])
{
    printf("in %s gAll is %d\n", __func__, gAll);  // 表示当前函数的名字，用%s输出
    f();
    printf("agn in %s gAll is %d\n", __func__, gAll);

    return 0;
}

int f(void)
{
    int gAll = 1;  // 与全局变量同名，全局变量被隐藏
    {
        int gAll = 2;  // 本地变量同理，内层的变量会把外层的同名变量隐藏
        printf("in %s gAll is %d\n", __func__, gAll);
        gAll += 2;
        printf("agn in %s gAll is %d\n", __func__, gAll);
    }

    return gAll;
}