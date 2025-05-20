/* 
putchar
int putchar(int c);
向标准输出（命令行窗口）写一个字符
返回写了几个字符，EOF(-1)（End of File）表示写入失败

getchar
int getchar(void);
从标准输入读一个字符
返回类型是int，为了能返回EOF(-1)所以是int
    Windows； Ctrl+Z
    Unix；Ctrl+D
（Ctrl+C强制程序结束）

为什么getchar一次只读一个字符，而我们输入很多字符，直到回车以后才执行后面的代码？
大致可以解释为（具体实现原理更复杂）：
键盘（用户输入） ->  shell（读取用户输入放入缓冲区，再传入程序）  ->  程序（getchar读取字符，直达换行）
putchar同理，scanf("%d", a)连续读取整数字符直到空格
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int ch;

    while ((ch = getchar()) != EOF)
    {
        putchar(ch);
    }

    printf("EOF\n");
    
    return 0;
}