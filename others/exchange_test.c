#include <stdio.h>

int main()
{
    int integer1, integer2;
    printf("请输入第一个整数：");
    scanf("%d", &integer1);
    printf("请输入第二个整数：");
    scanf("%d", &integer2);

    integer1 = integer1 ^ integer2;
    integer2 = integer1 ^ integer2;
    integer1 = integer1 ^ integer2;

    printf("integer1: %d\n", integer1);
    printf("integer2: %d\n", integer2);

    printf("char: %d.\n", sizeof(char));
    printf("short int: %d.\n", sizeof(short));  // short == short int
    printf("int: %d.\n", sizeof(int));
    printf("long int: %d.\n", sizeof(long));  // long == long int
    printf("float: %d.\n", sizeof(float));
    printf("double float: %d.\n", sizeof(double));

    int num = 32333;
    printf("num: %d.\n", sizeof(num));

    return 0;
}