#include <stdio.h>

/*  字符类型
char是一种整数，也是一种特殊的类型：字符�?
    用单引号表示字符的字面量�?'a','1'
    '' 也是一�? 字符
    printf和scanf里用%c来输出输入字�?
*/

int main()
{
    char c;
    char d;
    c = 1;  // 整数
    d = '1';  // 字符

    char e;
    int f;
    //scanf("%c", &e);
    scanf("%d", &f);  // 假如输入的是49
    e = f;  // 整数f=49,e=f=49,以%d输出为整数49，以%c输出为字符1

    if (c == d) {
        printf("相等\n");
    } else {
        printf("不相等\n");
    }

    printf("c=%d\n", c);
    printf("d=%d\n", d);
    printf("\n");

    printf("e=%d\n", e);
    printf("e='%c'\n", e); 
    printf("\n");

    return 0;
}