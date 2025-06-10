// 创建一个操作可变大小的数组的函数库
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 创建Array类型的数组结构的函数
Array array_create(int init_size)
{
    Array arr;
    arr.size = init_size;
    arr.array = (int*)malloc(arr.size * sizeof(int));
    
    return arr;
}

const int BLOCK_SIZE = 20;

// 释放创建数组时分配的内存
void array_free(Array *parr)  // 必须传入指针，才能释放内存
{
    free(parr->array);  // arr所指的结构的成员array是个指针，并且使用malloc分配了内存，所以要free(arr->array)而不是free(arr)
    parr->array = NULL;  // 将指针array置空，避免多次调用这个函数进行free从而造成程序出错，free(NULL)是无作用无害的
    parr->size = 0;  // array置空后，数组尺寸size自然为0
}

// 查询数组的大小
// 为什么不直接使用arr.size获取数组大小而是要用函数实现呢？
// 这种作法叫做封装，有隐藏内部实现细节，包含数据，便于维护更新等等诸多好处。
int array_size(Array *parr)
{
    return parr->size;   
}  

// 访问数组中的某个单元
int* array_at(Array *parr, int index)  // 返回对应数组单元的指针
{
    // 当访问的下标越界时，自动扩展数组大小
    if (index >= parr->size) {
        // array_inflate(parr, index + 1 - parr->size);  // 如果每次只扩展1，不太经济
        array_inflate(parr, (index / BLOCK_SIZE + 1) * BLOCK_SIZE - parr->size);  // 每次扩展一个BLOCK_SIZE的大小
    }

    // 返回下标对应的数组单元的指针
    return &(parr->array[index]);
}
    // 直接返回变量只能得到该数组单元的值，无法给它赋值
    // 返回指针：
    // *array(&arr, 0) = 10;  // 可以直接赋值
    // printf("%d\n", *array(&arr, 0))  // 输出值需要加*

// 也可以分成获取数组单元的值和设置数组单元的值这两个函数来实现
// void array_set(Array *parr, int index, int value)
// {
//     parr->array[index] = value;
// }
// 
// int array_get(const Array *parr, int index)  // 传入的指针指向的变量的值不会修改，因此是const
// {
//     return parr->array[index];
// }


// 扩张数组大小
void array_inflate(Array *parr, int more_size)
{
    // 使用malloc创建新数组来扩展数组大小
    int *p = (int*)malloc(sizeof(int) * (parr->size + more_size));

    // 遍历来复制数组单元的值到新数组:
    // for (int i = 0; i < parr->size; i++)
    // {
    //     new_arr[i] = parr->array[i];
    // }

    // 使用memcpy来复制数组单元到新数组:  // 注意是me m cpy 而不是 me n cpy
    // 需要#include <string.h>
    // void* memcpy(void* dest, const void* src, size_t n);
    // 功能：从源地址 src 复制 n 字节的数据到目标地址 dest。
    // 参数：dest：目标内存区域的起始地址（指针类型为 void*，可接受任意类型的指针）。
    //      src：源内存区域的起始地址（const void* 表示只读，防止修改源数据）。
    //      n：要复制的字节数（类型为 size_t，通常是无符号整数）。
    // 返回值：返回指向目标区域 dest 的指针。
    memcpy(p, parr->array, sizeof(int) * parr->size);
    free(parr->array);  // 先将原指针指向的内存释放掉，因为后面会对该指针操作后就无法找到原指针的地址了
    parr->array = p;
    parr->size += more_size;


    // 使用realloc直接扩展数组大小:
    // int *p;
    // p = realloc(parr->array, sizeof(int) * (parr->size + more_size));
    // if (p == NULL) {  // 注意是==而不是=
    //     // 处理失败时，arr仍有效
    // } else {
    //     parr->array = p;
    //     parr->size += more_size;
    // }
}

void array_print(const Array *arr)
{
    for (int i =0; i < arr->size; i++) {
        printf("%d ", arr->array[i]);
    }
}