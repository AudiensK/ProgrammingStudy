#include <stdio.h>

int main()
{
    char str[] = "ABd123";  // 字符串要用双引号
    // char str = "ABd123" 是错误的
    char chr = 'A';  // 字符要用单引号
    printf("%s\n", str);
    printf("%c\n", chr);

    int a = 7;
    printf("%d\n", a = 8 > 9);  // 先比较后赋值

    return 0;
}