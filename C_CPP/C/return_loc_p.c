// *返回指针的函数
// 返回本地变量的地址是危险的
// 返回全局变量或静态本地变量的地址是安全的
// 返回函数内malloc的内存是安全的，但是容易造成问题
// *最好的做法是返回传入的指针

#include <stdio.h>


int *f(void);
void g(void);


int main(void)
{
    int *p = f();
    printf("*p=%d\n", *p);
    g();
    printf("*p=%d\n", *p);

    return 0;
}

int *f(void)
{
    int i =2;
    return &i;  // 返回局部变量的指针会造成错误
}

void g(void)
{
    int k = 4;
    printf("k=%d\n", k);
}
