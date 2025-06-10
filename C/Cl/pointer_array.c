#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//void minmax(int a[], int len, int *max, int *min);
void minmax(int *a, int len, int *max, int *min);
/*  数组变量是特殊的指针
数组变量本身表达地址，所以int a[10];int *p = a;无需用&取地址
但是，数组单元表达的是变量，需要用&取地址，int *p = &a[0];
a == &a[0];数组中第一个单元的地址就等于数组的地址；
[]方括号运算符可以对数组做，也可以对指针做：
int *p = &min;
printf("*p=%d\n", *p);
printf("p[0]=%d\n", p[0]);
*星号运算符可以对指针做，也可以对数组做：
printf("*a=%d\n", *a);

数组变量可以被看做const的指针，不能被赋值
所以int a[10];int b[];b=a;这样写是错误的
但是 int *q = a; 这种写法可以
*/

int main()
{
    srand(time(0));
    int a[10];
    printf("a[10]={");
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i ++) {
        a[i] = rand() % 100;
        printf("%d, ", a[i]);
    }
    printf("}\n");
    printf("\n");

    int min, max;

    printf("main sizeof(a)=%lu\n", sizeof(a));
    printf("main a=%p\n", a);  // 获取数组地址
    printf("\n");

    minmax(a, sizeof(a)/sizeof(a[0]), &min, &max);
    printf("min=%d,max=%d\n", min, max);
    printf("a[0]=%d\n", a[0]);
    printf("\n");
    
    int *p = &min;  // 获取变量min的地址
    printf("*p=%d\n", *p);  // 输出指针p指向的变量min的值
    printf("p[0]=%d\n", p[0]);  // 把指针p当作数组，输出数组单元的值
    // 可以得知以上两个输出的值相等
    printf("*a=%d\n", *a);  // a是一个数组，把数组当作指针输出，等同于输出a[0]的值
    printf("\n");

    int ab[] = {1, 2, 3, 4, 5, 6};
    int *pab = &ab[2];
    printf("pab[-2]=%d\n", pab[-2]);

    return 0;
}

//void minmax(int a[], int len, int *min, int *max)  // 传入参数int a[]其实是个指针
void minmax(int *a, int len, int *min, int *max)  // 因此将传入参数改成int *a也能通过编译
{
    int i;

    printf("minmax sizeof(a)=%lu\n", sizeof(a));
    printf("mimmax a=%p\n", a);
    a[0] = 100;  // 由于传入的数组是指针，所以可以直接在函数内修改数组中的元素

    *min = *max = a[0];
    for (i = 1; i < len; i ++) {
        if (a[i] >= *max) {
            *max = a[i];
        }
        if (a[i] <= *min) {
            *min = a[i];
        }
    }
}