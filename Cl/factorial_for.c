#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int factor = 1;

    // int i = 1;
    /* for循环相当于python中的for-in，不过C语言中是基于计数器的循环，python是基于可迭代对象的循环。
    for (初始化表达式; 条件表达式; 更新表达式)
    {
        // 循环体（要重复执行的代码）
    }
    */
    for (int i = 1; i <= n; i++) {  // 只有支持c99的编译器才能在for（）内部直接定义变量
        factor *= 1;
    }

    printf("%d!=%d\n", n, factor);

    return 0;
}
/* 
for循环和while循环是等价的；
如果有固定次数，用for循环；
如果必须执行一次，用do-while循环；
其他用while循环。
*/