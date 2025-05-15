#include <stdio.h>

// &用于获得变量的地址，它的操作数必须是变量；C语言的变量是放在内存里的
// &不能对没有地址的东西取地址

int main(void)
{
    int i = 10;
    int p;
    //p = (int)&i; // 强制类型转换：(type) expression;这里的 type 代表目标数据类型，expression 是需要进行转换的表达式。
    printf("&i=0x%x\n", &i);  
    //printf("0x%x\n", p);  
    // %x 以十六进制无符号整数形式输出。%x 输出小写字母的十六进制数，%X 输出大写字母的十六进制数。
    // &i意思是i的地址，以上方法会出现警告或报错，因为%x不适合输出地址，应该用%p输出地址
    printf("&i=%p\n", &i);

    printf("\n");

    // 在64位架构下，int是4个字节，&i取出的地址是8个字节，32位地址也是4个字节，是否相等取决于编译器和CPU架构
    printf("sizeof(int)=%lu\n", sizeof(int));  // %lu 是以十进制无符号长整数形式输出 unsigned long 类型的值。
    printf("sizeof(&i)=%lu\n", sizeof(&i));

    printf("\n");

    int a = 0;
    int b = 1;
    // C语言的变量（栈区变量）在内存中是有顶部向下存储的，先定义的变量地址更高，后定义的更低，栈区变量是从高地址向低地址增长的；
    // 使用 malloc、calloc 等函数动态分配的内存位于堆区。堆的增长方向是从低地址向高地址。
    // 由以下结果可以得知a、b这两变量在内存中是紧挨着的，且地址相差4
    printf("&a=%p\n", &a);
    printf("&b=%p\n", &b);

    printf("\n");

    //int c[10];
    double c[10];
    printf("&c=%p\n", &c);
    printf("c=%p\n", c);  // c是数组，类似于指针，直接printf会输出c的地址
    // 整数数组中每个单元在内存中也是紧挨着存放的，且每个单元直接相差4；不同类型数据地址相差不一样
    printf("&c[0]=%p\n", &c[0]);
    printf("&c[1]%p\n", &c[1]);

    return 0;
}