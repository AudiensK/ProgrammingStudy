#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

    int digit;
    int ret = 0;

    while (num > 0) {
        digit = num % 10;
        printf("%d", digit);
        num /= 10;
        ret = ret * 10 + digit;
        // printf("num = %d, digit = %d, ret = %d\n", num, digit, num);
    }
    // printf("ret = %d", ret);

    return 0;    
}