#include <stdio.h>

int main()
{
    int x;  
    int n = 0;

    scanf("%d", &x);

    do // do{}while();先执行循环内容再判断循序条件，相比于while，do-while至少会执行一遍循环内容。
    {
        x /= 10;
        n++;        
    } while (x > 0);  // 记得while()后面的;

    printf("%d", n);

    return 0;
}