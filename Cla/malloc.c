#include <stdio.h>
#include <stdlib.h>  // 使用malloc需要包含stdlib.h

// memory allocation（内存分配）
//它用于在程序运行时动态地从堆内存中分配指定大小的连续内存空间，并返回一个指向该内存区域的指针。

/*如果输入数据时，先告诉你个数，然后再输入，要记录每个数据
c99可以用变量做数组定义的大小，
c99之前：
int *a = (int*)malloc(n*sizeof(int));
  malloc(需要的内存空间所占用的字节大小)，分配好空间后再用(type*)类型转换为type类型的指针，再赋值给一个指针变量
*/

/* malloc()
# include <stdlib.h>
void* malloc(size_t size);
向malloc申请的空间大小是以字节为单位的，如果申请失败，返回0或NULL
返回的结果是void*，需要转换成自己需要的类型
  (int*)malloc(n*sizeof(int));
*/

// 单次malloc得来的空间是连续的，相邻两次malloc的空间 通常不连续，但可能相邻

/* free()
把申请来的空间还给“系统”
  申请过的空间，最终都是要换的
只能还申请来的空间的首地址
    int i;
    void *p = 0;  // 
    p = malloc(10*1024*1024);
    //p++;
    p = &i;

    //free(p);  // 会报错，因为p已经不是原来申请时的地址了
    free(NULL);  // 不会报错
    //free(NULL)是一个安全的操作，它没有实际的作用，但也不会导致程序出错
    //这种特性使得在编写代码时，可以不必特意添加额外的逻辑来判断指针是否为 NULL 后再调用free函数，简化了代码结构
    //养成良好习惯，每次定义指针时都初始化为0

常见问题：
申请内存没有free，可能会导致 长时间运行内存下降
  忘了，找不到合适时机free
free过后再次free
地址变过以后再去free

在 C 语言中，只要使用malloc、calloc或realloc动态分配了内存，就必须使用free释放该内存，以避免内存泄漏。
比如在一个函数内部使用malloc分配了内存，这个函数就必须return一个指针用于free掉申请的内存，或者直接在该函数内部释放内存，避免内存泄漏
*/

// calloc：分配指定数量和大小的内存块，并将所有字节初始化为 0，接受两个参数 nmemb 和 size，分别表示元素个数和每个元素的大小，总分配字节数为 nmemb * size。
// calloc：分配的内存会初始化为全 0（每个字节都是 0x00）。
// calloc 的参数可能导致整数溢出（例如 nmemb * size 超过 size_t 的范围），此时行为未定义。
// calloc：由于需要初始化内存为 0，可能稍慢，但适合需要零初始化的场景（如存储敏感数据或用作位图）。

// realloc：调整现有内存块的大小，可能需要移动内存位置。常用于动态扩容或缩容。
// int* arr = (int*)malloc(5 * sizeof(int));  // 初始分配5个int
// arr = (int*)realloc(arr, 10 * sizeof(int));  // 扩容为10个int
// 内存移动：若原内存块后空间不足，会在新位置分配内存，并复制原内容，然后释放原内存。
// 缩容处理：若缩小内存，多余部分被释放，原有数据保留。
// 扩容注意：若扩容后返回NULL，原指针仍有效，需手动释放。
// 特殊用法：
// realloc(NULL, size) 等价于 malloc(size)。
// realloc(ptr, 0) 等价于 free(ptr)（非标准，但常见），不同系统可能有不同实现，建议使用free(ptr)。
// 若realloc失败，原指针仍需手动释放：
// int* new_ptr = realloc(old_ptr, new_size);
// if (new_ptr == NULL) {
//     // 处理失败，old_ptr仍有效
// } else {
//     old_ptr = new_ptr;  // 更新指针
// }
// 指针有效性：realloc后原指针可能失效，需使用返回值。

int main()
{
    int number;
    int *a;  // c99之前先要定义个指针
    int i;
    printf("输入数量：\n");
    scanf("%d", &number);
    //int a[number];  // c99可以直接用变量做数组大小

    //分配内存
    a = (int*)malloc(number * sizeof(int)); 
    //输入数据
    for (i = 0; i < number; i++) {
        scanf("%d", &a[i]);
    }
    //输出数据
    for (i = 0; i< number; i++) {
        printf("%d ", a[i]);
    }
    //释放内存空间
    free(a);
    a = NULL;  // free过后可以置空指针，再次free时候就不会出错
    free(a);  // free已经释放的空间或错误的指针会导致运行时出现未定义行为

    // int *b = &i;
    // int c;
    // b = 0;  // 等同于b = NULL;                                    // 不过将指针置空，free时就不会出错
    // free(b);  // free的指针不是指向动态分配的内存(比如释放栈上的变量)，也会出现未定义行为，该行为十分危险
    // free(c);  // free非指针会编译报错

    return 0;
}