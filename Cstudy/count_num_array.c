#include <stdio.h>

int main()
{
    const int NUMBER = 10;  // 数组大小
    int x;
    int count[NUMBER];  // 定义数组
    int i;
    
    // 初始化数组
    for (i = 0; i < NUMBER; i ++) {
        count[i] = 0;
    }

    scanf("%d", &x);
    while ( x != -1) {
        if ( x > 0 && x < 9) {
            count[x] ++;  // 数组参与运算
            scanf("%d", &x);
        }
    }

    // 遍历数组输出结果
    for (i = 0; i < NUMBER; i ++) {
        printf("%d出现%d次\n", i, count[i]);
    }

    return 0;
}