#include <stdio.h>

int main() {
    int low = 1, high = 1000000, mid;
    int response;
    int result;

    printf("请想一个1到1000000之间的整数，我会开始猜。\n");

    while (1) {
        mid = (low + high) / 2;
        printf("我猜这个数是 %d。请输入0（大了）、1（小了）、2（正确）或 -1（结束程序）：", mid);
        result = scanf("%d", &response);
        // 清空输入缓冲区
        while (getchar() != '\n'); 

        if (result != 1) {
            printf("输入无效，请输入有效的整数。\n");
            continue;
        }

        if (response == -1) {
            printf("程序结束。\n");
            break;
        } else if (response == 0) {
            high = mid - 1;
        } else if (response == 1) {
            low = mid + 1;
        } else if (response == 2) {
            printf("我猜对啦！游戏结束。\n");
            break;
        } else {
            printf("输入无效，请输入0、1、2或 -1。\n");
        }
    }

    return 0;
}