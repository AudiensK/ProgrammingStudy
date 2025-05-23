// 静态本地变量
// 在本地变量定义是加上修饰符static就成为静态本地变量
// 当函数离开时候，静态本地变量仍会继续存在并保持其值
// 静态本地变量初始化只会在第一次进入这个函数时做，以后进入函数时候会保持上次离开时候的值

// 静态本地变量实际上时特殊的全局变量
// 它们位于相同的内存区域
// 静态本地变量具有全局的生存期，函数内的局部作用域（全局变量则时全局作用域）
//  static在这里的意思是局部作用域（本地可访问）


// 不对外公开的函数
// 在函数前面加上static就使得它成为只能在所在的编译单元中被使用的函数
// 在全局变量前面加上static就使得它成为只能在所在的编译单元中被使用的全局变量


#include <stdio.h>

int g = 1;

int f(void);


int main(int argc, const char *argv[])
{
    static int s1 = 2;
    int l = 3;

    f();
    f();
    f();
    printf("\n");

    printf("&g: %p\n", &g);
    printf("&s1:%p\n", &s1);
    printf("&l: %p\n", &l);

    return 0;
}

int f(void)
{
    static int s = 1;  // 初始化只会在第一次执行

    printf("in %s s is %d\n", __func__, s);
    s += 2;
    printf("agn in %s s is %d\n", __func__, s);

    return s;
}