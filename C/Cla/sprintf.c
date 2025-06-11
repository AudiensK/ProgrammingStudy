#include <stdio.h>

/* sprintf 是 C 语言标准库中的一个格式化输出函数，它与 printf 功能类似，但输出方向不同：
    printf 将格式化后的字符串输出到标准输出（通常是控制台），
    而 sprintf 将格式化后的字符串存储到指定的字符数组中。
    int sprintf(char *str, const char *format, ...);
        str：指向目标字符数组的指针，用于存储格式化后的字符串。
        format：格式化字符串，包含普通字符和格式说明符（如 %d、%s、%f 等）。
        ...：可变参数列表，根据 format 中的格式说明符提供对应的值。
    成功：返回写入到字符数组中的字符数（不包括终止符 '\0'）。失败：返回负值。*/

int main(void)
{
    char format[10];
    int n;
    printf("输入小数显示的位数：");
    scanf("%d", &n);
    sprintf(format, "%%.%df", n);

    printf("%s\n", format);
    printf(format, 1.123456789);

}