#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *p;
    int cnt = 0;
    // 最大能申请多少空间，如果申请失败，返回0或NULL，循环结束
    while ( (p = malloc(100*1024*1024)) ) {  // 1024是1K字节，1024*1024就是1M
        cnt ++;
    }
    printf("分配了%d00M的空间\n", cnt);  // 不同架构结果不一样

    return 0;
}