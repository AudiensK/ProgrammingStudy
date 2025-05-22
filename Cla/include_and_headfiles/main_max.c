#include "max.h"


// double max(int a, int b);
// bool if_abtb(int a, int b);


int main(void)
{
    int a;
    int b;

    printf("Keying two numbers in:");
    scanf("%d %d", &a, &b);

    printf("Bigger number is %lf.\n", max(a,b));

    if (if_abtb(a, b)) {
        printf("a=%d,b=%d,a>b\n", a, b);
    } else {
        printf("a=%d,b=%d,a<b\n", a, b);
    }


    // 暂停程序，等待用户输入
    printf("Any Button to Continue...\n");
    getchar();  // 读取一个字符
    getchar();  // 如果前面有输入，需要再读取一次以消耗掉换行符
    // 第一个getchar()会读取用户的输入。
    // 第二个getchar()的作用是处理可能存在的缓冲区内的换行符。
    // 要是你的程序在这之前没有任何输入操作，第二个getchar()就可以省略。

    return 0;
}