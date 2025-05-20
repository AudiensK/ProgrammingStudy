#include <stdio.h>
#include "array.h"


int main()
{
    // 创建数组
    Array arr1 = array_create(3);
    // 输出数组大小
    printf("%d\n", array_size(&arr1));
    // 访问数组单元并赋值
    *array_at(&arr1, 0) = 6;
    // 无限读入整数并写入数组
    int number;
    int cnt = 0;
    while (number != -1) {
        scanf("%d", &number);
        if (number != -1) {  // 避免将-1写入数组
            *array_at(&arr1, cnt++) = number;
        }
        // scanf("%d", array_at(&arr1, cnt++));  // array_at()返回的是指针，所以不需要&寻址
    }
    // 输出数组
    printf("%d\n", array_size(&arr1));
    array_print(&arr1);
    
    // 释放内存
    array_free(&arr1);

    return 0;
}

// 编译指令：
// gcc array.c main_array.c -o resizable_array.exe