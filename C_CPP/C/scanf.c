#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;

    scanf("%d %d", &a, &b);  // 输入：1 2
    printf("%d %d\n", a, b);  // 输出：1 2

    scanf("%d, %d", &a, &b);  // 输入：1 2；                 输入：1,2
    printf("%d %d\n", a, b);  // 输出：1 0  第二个数未读取；  输出：1 2  第二个数正确读取；

    scanf("%d %d ", &a, &b);  // 输入：1 2 ；  第二个数后面需要输入空格或其他字符以满足scanf中第二个%d后面的空格，/n同理
    printf("%d %d\n", a, b);  // 输出：1 2

    scanf("price%d %d", &a, &b);  // 输入：1 2；  输入：price 1 2；  出现在scanf "" 格式中的字符是必须要输入的
    printf("%d %d\n", a, b);  // 输出：0 0；      输出：1 2

    // scanf里的&是获得变量的地址，它的操作数必须是变量；C语言的变量是放在内存里的

    return 0;
}