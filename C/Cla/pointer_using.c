#include <stdio.h>
// 指针的应用

void swap(int *pa, int *pb);
void ab(int *pa, int *pb);
int divide(int *da, int *db, double *dc);

int main(void)
{
    int a = 3;
    int b = 6;

    // 交换变量得值
    swap(&a, &b);
    printf("swaped a=%d\nswaped b=%d\n", a, b);
    printf("\n");

    // 指针返回多个值
    ab(&a, &b);
    printf("ab a=%d\nab b=%d\n", a, b);
    printf("\n");

    // 函数返回状态，指针返回值
    double c;
    if (divide(&a, &b, &c)) {
        printf("%d/%d=%lf\n", a, b, c);
    } else {
        printf("%d/%d是无效运算\n", a, b);
    }
    printf("\n");

    return 0;
}

// 交换两个变量的值
void swap(int *pa, int *pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

// 函数需要返回多个值，传入的参数就是需要保存带回结果的变量
void ab(int *pa, int *pb)
{
    *pa = 7;
    *pb = 0;
}

// 函数返回运算的状态，结果通过指针返回
    // 比如让函数返回特殊的不属于有效范围内的值来表示出错，但是当任何值都是有效的结果时，就得分开返回
    // C语言只能通过指针返回结果和return返回异常值来解决这个问题，后续语言（C++，java等）则采用了异常机制
int divide(int *da, int *db, double *dc)
{
    int ret = 0;
    if (*db) {
        *dc = *da / (*db * 1.0);
        ret = 1;
    }
    return ret;
}