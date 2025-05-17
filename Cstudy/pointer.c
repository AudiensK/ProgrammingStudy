#include <stdio.h>


void f(int *p);
void g(int k);

int main()
{
    // 指针（pointer）就是保存地址的变量
    int i = 6;
    /*
    *是一个单目运算符号，用来访问指针的值所表示的地址上的变量
    既可以做左值，也可以做右值
    int k = *p;  // 读
    *p = k + 1;  // 写
    */
    int* p = &i;  // p是一个指针，指向变量i；int表示指针所指向的变量类型是int
    // int p = &i;  // 这种写法会报错
    // char *p = &i;  // 报错，因为i是int类型的变量
    /* 
    以下两种写法意义相同，要注意没有int*这种变量类型，* p和*p都代表指针类型变量，q只是int类型变量；
    int* p,q;
    int *p,q;
    */

    //
    printf("&i=%p\n", &i);
    printf("\n");
    f(&i);
    f(p);
    printf("\n");
    g(i);

    return 0;
}

void f(int *p)  // 传入指针p
{
    printf("p =%p\n", p);  // p的值是i的地址
    printf("*p=%d\n", *p);  // *p访问i的值
    printf("&p=%p\n", &p);  // &p访问的是指针p本身的地址，不是指针p所指向的地址
    // C语言函数调用时发生的参数的转移是一种值的传递，而通过传递指针可以直接访问外部变量
    *p = 26;  // 改变指针指向的变量的值
}

void g(int k)  // 传入变量k
{
    printf("k=%d\n", k);
}