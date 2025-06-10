#include <stdio.h>

int main()
{
    int x;
    int one, two, five;
    int exit = 0;

    scanf("%d", &x);
    for (one = 1; one <= x * 10; one ++) {
        for (two = 1; two <= x * 10 / 2; two ++) {
            for (five = 1; five <= x * 10 / 5; five ++) {
                if (one + two * 2 + five * 5 == x * 10) {
                    printf("可以用%d个1角和%d个2角和%d个5角凑出%d元钱。\n", one, two, five, x);
                    goto out;  // 可以直接用goto跳出循环到指定位置，out为自定的标号。
                    // goto会引起破坏代码结构与可读性、造成资源泄漏等诸多问题，尽量只在需要跳出多层循环的场景下使用。
                }
            }
        }
    }
out:
    return 0;
}