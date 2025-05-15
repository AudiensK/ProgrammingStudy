#include <stdio.h>

int main()
{
    int a = 10;

    printf("a++=%d\n", a++);
    printf("a=%d\n", a);

    printf("++a=%d\n", ++a);
    printf("a=%d\n", a);

    //在这个例子中，++i 先把 i 的值从 5 增加到 6，然后将增加后的值 6 赋给 j。所以，i 和 j 的最终值都是 6。
    int i = 5;
    int j = ++i;
    printf("i 的值是: %d\n", i); 
    printf("j 的值是: %d\n", j); 

    //在这个例子中，m++ 先把 m 当前的值 5 赋给 n，然后再将 m 的值加 1 变为 6。所以，i 的最终值是 6，而 n 的值是 5。
    int m = 5;
    int n = m++;
    printf("m 的值是: %d\n", m); 
    printf("n 的值是: %d\n", n);

    // 使用 i++ 的循环
    for (int i = 0; i < 5; i++)
        printf("%d ", i);
    printf("使用 i++ 循环结束后 i 的值: %d\n", i); 

    // 使用 ++i 的循环
    for (int i = 0; i < 5; ++i)
        printf("%d ", i);
    printf("使用 ++i 循环结束后 i 的值: %d\n", i);     

    return 0;
}