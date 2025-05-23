// #include有两种形式来指出要插入的文件
//  ""双引号要求编译器首先在当前目录（.c文件所在目录）寻找这个文件，如果没找到，到编译器指定目录寻找
//  <>尖括号让编译器只在指定目录寻找
// 编译器自己知道自己的标准库的头文件在哪里
// 环境变量和编译器命令行参数也可以指定寻找头文件的目录

// #include不是用来引入库的，它只是把头文件中的内容在预编译时插入源代码
// stdio.h里面只有函数原型（比如printf），函数的实现代码在另外的地方，某个.lib(windows)或.a(Unix)中
// 现在的C语言编译器会默认引入所有标准库（不需要的会去除），所以有时候没有#include某个标准库，编译也没问题，但是尽量避免这样做
// #include <stdio.h>只是为了让编译器知道printf函数的原型，保障你调用时给出的参数是正确的类型

#include <stdio.h>
#include "max.h"


// 如果没有原型声明，编译器会猜测参数类型和函数返回类型，有可能会出错
// 但是可以将原型声明放在头文件中，然后在这个文件中包含那个头文件
// double max(int a, int b);
// bool if_abtb(int a, int b);


int main(void)
{
    int a;
    int b;

    printf("Keying two numbers in:");
    scanf("%d %d", &a, &b);

    printf("max number is %lf.\n", max(a,b));

    if (if_abtb(a, b)) {
        printf("a=%d,b=%d,a>b\n", a, b);
    } else {
        printf("a=%d,b=%d,a<b\n", a, b);
    }

    printf("gAll=%d\n", gAll);

    // 暂停程序，等待用户输入
    printf("Any Button to Continue...\n");
    getchar();  // 读取一个字符
    getchar();  // 如果前面有输入，需要再读取一次以消耗掉换行符
    // 第一个getchar()会读取用户的输入。
    // 第二个getchar()的作用是处理可能存在的缓冲区内的换行符。
    // 要是你的程序在这之前没有任何输入操作，第二个getchar()就可以省略。

    return 0;
}


// 编译命令：gcc main_max.c max.c -o max_number