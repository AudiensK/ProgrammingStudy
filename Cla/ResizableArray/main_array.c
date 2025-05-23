// 通过malloc实现了一个可扩展大小的数组结构
// 但是随着数组的不断扩大，每次都需要申请一块新的内存，然后将原来的数据拷贝到新内存里，拷贝的时间开销变大
// 另外一个问题是有可能出现无法继续申请内存空间的情况，
// 比如内存受限的场景，
// 比如剩下的内存被现在数组占据的内存分割开，然而单独一块内存空间无法满足申请的需求
// 这时候需要使用 链表
#include "array.h"
#include <stdio.h>


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