#include <stdio.h>

int main()
{
    int x;

    scanf("%d", &x);

    // 级联写法更简洁易读
    int f = 0;  // 定义一个额外变量用于后面代码的逻辑判断或计算，符合 单一出口 原则，更灵活
    if (x < 0) {
        f = -1;
    } else if (x == 0) {  // else通常和前面最近的if匹配
        f = 0;
    } else {
        f = 2 * x;
    }

    /*  嵌套写法更复杂
    int f = 0;
    if (x < 0) {
        f = -1;
    } else {
        if (x == 0) {
            f = 0;
        } else {
            f = 2 * x;
        }
    }
    */
           
    printf("%d", f);

    /*  未定义额外变量，x的值可能改变，锁死了x的用途，较为死板
    if (x < 0) {
        x = -1;
    } else if (x == 0) {
        x = 0;
    } else {
        x = 2 * x;
    }

    printf("%d", x);
    */

    return 0;
}