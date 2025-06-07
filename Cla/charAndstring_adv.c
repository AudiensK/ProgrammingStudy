#include <stdio.h>

#define NEXTLINE printf("\n");


int main(void)
{
    char a[] = "我们";
    printf("%s\n", a);
    for (int i = 0; i < sizeof(a)/sizeof(a[0]) - 1; i ++) {
        printf("%d ", a[i]);
        // printf("%c ", a[i]);
    }

    NEXTLINE



    NEXTLINE

    for (int c = -128; c <= 127; c ++) {
        // char默认是有符号类型，其取值范围是 - 128 到 127。\
        当你写出char c = 128这样的初始化语句时，由于 128 超出了有符号char的表示范围，就会发生整数溢出。
        // 用char类型，到边界时变量c继续自增，会导致溢变为-128，从而无限循环下去
        // 无符号 char 类型,unsigned char,取值范围是 0 到 255
        printf("%d/%c ", c, c);
    }

    return 0;
}