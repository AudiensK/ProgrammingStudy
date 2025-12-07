#include <stdio.h>

int main()
{
    int m[][3] = {1, 4, 7, 2, 5, 8, 3, 6, 9};  // 相当于int m[][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    int i, j, k = 2;  // 只有最后哪个变量k被赋值了
    for (i = 0; i < 3; i ++) {
        printf("%d", m[k][i]);
    }

    return 0;
}