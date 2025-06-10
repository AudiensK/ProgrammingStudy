/* 程序参数
int main(int argc, char const *argv[])  // argc告诉我们后面的数组有多少个字符串，argc是个字符串数组
argv[0]是命令本身
    当使用Unix的符号链接时，反映符号链接的名字
    在Unix系统中用途很大
    在Windows中，一般使用快捷方式运行exe程序，但是也可以在快捷方式后面添加参数
*/


#include <stdio.h>

int main(int argc, char const *argv[])  // 在命令行运行命令后面跟上参数，比如.\main_parameter.exe 123 124 125 abc
{
    int i;
    for (i = 0; i < argc; i++) {
        printf("%d:%s\n", i, argv[i]);
    }

    return 0;
}