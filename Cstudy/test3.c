#include <stdio.h>

int main() {
    char *str = "Hello";  // "Hello" 是常量，存放在常量区
    int num = 10;         // num 是局部变量，存放在栈区
    printf("Address of constant string: %p\n", (void *)str);
    printf("Address of variable: %p\n", (void *)&num);
    /*
    void * 是一种通用指针类型，它可以指向任意类型的数据，并且可以和其他任何类型的指针进行相互转换。
    在代码中，str 通常是一个具体类型的指针，比如 char * 类型的指针。虽然在大多数系统中，
    不同类型的指针在内存中占用的字节数是相同的，并且都可以表示内存地址，
    但为了遵循 %p 格式说明符的要求，需要将 str 强制转换为 void * 类型的指针。
    */

    printf("%p\n", str);
    printf("%ld\n", &num);

    printf("\n");

    int i = 1;
    int *p = &i;
    printf("&i=%p\n", &i);
    printf("&p=%p\n", &p);
    printf("p =%p\n", p);

    return 0;
}