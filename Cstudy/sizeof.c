#include <stdio.h>

int main()
{
    int a;
    a = 6;

    printf("sizeof(int)=%ld\n", sizeof(int));  // 一个字节==8比特
    printf("sizeof(a)=%ld\n", sizeof(a));  // %ld或%li 是以十进制有符号长整数形式输出 long 类型的值
    printf("sizeof(float)=%ld\n", sizeof(float));
    printf("sizeof(double)=%ld\n", sizeof(double));
    printf("sizeof(char)=%ld\n", sizeof(char));
    printf("\n");

    printf("char: %zu bytes\n", sizeof(char));  // %zu 是用于格式化输出 size_t 类型值的格式说明符，能提高代码在不同平台上的可移植性。
    printf("int: %zu bytes\n", sizeof(int));
    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));
    // 上述数据类型的大小是典型值，具体大小可能会因编译器、操作系统和硬件平台的不同而有所差异。
    printf("type: %zu bytes\n", sizeof(int *));
    // type * 指向 type 类型变量的指针，例如 int * 是指向 int 类型的指针。
    //在 32 位系统中，指针大小通常是 4 字节；在 64 位系统中，指针大小通常是 8 字节。

    return 0;
}