#include <stdio.h>

// union（联合）
/*  所有成员共享一个空间
    同义时间只有一个成员是有效的
    union的大小是其最大的成员
    对第一个成员做初始化
*/
typedef union {
    int i;
    char ch[sizeof(int)];
} CHI;

int main(int argc, char const *argv[])
{
    CHI chi;
    int i;
    chi.i = 1234;
    for (i = 0; i < sizeof(int); i++)
    {
        printf("%02hhX", chi.ch[i]);  // 输出结果D2040000  // x86 小端字节序（低位优先）
    }
    printf("\n");

    return 0;
}