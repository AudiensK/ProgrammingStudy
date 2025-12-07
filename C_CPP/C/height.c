#include <stdio.h>

int main()
{
    printf("请分别输入身高的英尺和英尺，"
    "如输入\"5 7\"表示5英尺7英尺：");

    // int foot;
    // int inch;
    double foot;
    double inch;

    // scanf("%d %d", &foot, &inch);  //输入5 7，输出1.524，C语言中两个整数运算，输出结果也是整数
    scanf("%lf %lf", &foot, &inch);  // 输入时用%lf

    printf("身高为%f米。\n",   // 输出时候用%f
        ((foot + inch / 12) * 0.3048));  //整数除以整数，得到的结果不会四舍五入，而是直接丢弃小数部分
        // 修改方法1：12改成浮点数12.0
        // 修改方法2：把定义变量的int换成double(双精度浮点数)，scanf中的%d换成%lf(long float)；也可换成float（单精度浮点数）和%f。
    return 0;
}