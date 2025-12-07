#include <stdio.h>
#include <stdbool.h>  //c99引入布尔数据类型，需要包含此头文件。

int main()
{
    bool b = 6 > 5;
    bool t = true;
    bool f = false;
    t = 2;  // 但是C语言没有真正的布尔类型，其本质仍然是整数。
    printf("%d\n%d\n%d\n", b, t, f);  // 只能把布尔类型输出为一个整数。

    return 0;
}