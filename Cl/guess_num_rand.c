#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int number = rand() % 100 + 1;
    int count = 0;
    int i = 0;

    printf("我已经想好了一个1到100之间的数（含1和100）。\n");

    do {
        printf("请猜这个1到100之间的数（含1和100）：");
        scanf("%d", &i);
        count ++;
        if (i > number) {
            printf("你猜的数大了,");
        } else if (i < number) {
            printf("你猜的数小了,");
        }
    } while (i != number);

    printf("恭喜你！你用了%d次就猜到答案了。", count);

    return 0;
}