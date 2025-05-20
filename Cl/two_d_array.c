#include <stdio.h>

int main() {
    // 创建一个3行4列的二维数组，并进行部分初始化
    int arr1[3][4] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };

    // 创建一个2行3列的二维数组，并完全初始化
    int arr2[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // 打印arr1的元素
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }

    // 打印arr2的元素
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}