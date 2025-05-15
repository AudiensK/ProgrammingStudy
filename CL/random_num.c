#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int a = rand();

    printf("%d", a % 100);  // 用100取余数，得到100以内的整数

    return 0;
}