#include <stdio.h>

int main()
{
    int num;
    int x = -1;

    printf("出题方输入一个100以内的正整数（含0,输入小数结束游戏）：");
    scanf("%d", &num);
    if (num >=0) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n猜数方输入猜的整数（输入小数结束游戏）：");
        do {
            scanf("%d", &x);
            if (x >= 0) {
                if (x >num) {
                    printf("大了，请再输入一个数：");
                } else if (x < num) {
                    printf("小了，请再输入一个数：");
                } else {
                    printf("恭喜你猜对了");
                }
            } else {
                printf("游戏结束，正确答案为%d。", num);
            }
        } while (x != num);
    } else {
        printf("游戏结束");
    }

    return 0;
}