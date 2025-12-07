#include <stdio.h>


int main()
{
    int a;
    scanf("%d", &a);
    printf("%d\n", a);

    return 0;
}


// PowerShell 不支持使用<符号进行输入重定向。这是 PowerShell 和传统 Unix shell（如 Bash）的一个重要区别。
// 在 PowerShell 中，可以通过管道将文件内容传递给程序：
// Get-Content 12345.txt | ./file_in.exe