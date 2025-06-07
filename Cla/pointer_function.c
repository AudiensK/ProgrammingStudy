// 函数指针
#include <stdio.h>

#define NEXTLINE printf("\n");

void f(int i, double j);
void g(int a);
void h(int a);
void j(int a);
void callfunc(int (*fp)(int a, int b), int a, int b);
int plus(int a, int b);
int minus(int a, int b);


int main()
{
    int i = 1;
    int *pi = &i;
    int a[2];
    printf("&i=%p\n", &i);
    printf("pi=%p\n", pi);
    printf("a=%p\n", a);
    NEXTLINE
    
    printf("main=%p\n", main);  // main函数名，在表达式中隐式转换为 void (*)()
    printf("*main=%p\n", *main);  // *main解引用函数指针，结果仍会被转换为 void (*)()
    printf("&main=%p\n", &main);  // &main指向函数的指针,类型为 void (**)()，但数值与 main 相同
    // 以上三个写法结果相同
    printf("f=%p\n", f);
    printf("g=%p\n", g);

    NEXTLINE

    // 单独一个函数名字不带括号表示函数的地址，加上()执行函数
    // f;
    f(i, 10.0);

    // 定义函数指针
    void (*pf)(int, double) = f;  // 返回类型 (*名字)(参数类型列表) = 函数名字;
    // 调用指针函数
    (*pf)(10, i*1.0);  // (*函数指针名字)(参数);

    NEXTLINE

    // 根据用户输入决定执行的函数
    printf("Entering a number(0~2):");
    // scanf("%d", &i);
    i = 0;

    // // if else
    // if (i == 0) g(i);
    // else if (i == 1) h(i);
    // else if (i == 2) j(i);
    // else printf("Invalid Input");

    // // switch case
    // switch(i)
    // {
    //     case 0: g(i); break;
    //     case 1: g(i); break;
    //     case 2: g(i); break;
    //     default: printf("Invalid Input"); break;
    // }

    // functional pointer
    void (*fa[])(int i) = {g, h, j};  // 定义一个函数指针数组，可以直接再这个数组中添加和删减函数，更方便维护
    if (i >= 0 && i < sizeof(fa)/sizeof(fa[0])) {  // fa为指针数组，fa[0]为数组中的单元，即函数指针
        (*fa[i])(i);  // (*fa[i])(i)调用该函数指针指向的函数
    } else {
        printf("Invalid Input");
    }

    NEXTLINE

    // 将函数作为变量传递给其他函数
    int aa = 3, bb = 9, cc = 1;
    int (*fp1)(int, int);
    fp1 = plus;
    callfunc(fp1, aa, bb);
    // callfunc(fp1(aa, bb), aa, bb);  
    // 以上写法错误，因为fp1(aa, bb)是调用函数，返回结果为int，而传入的应该是函数本身，即函数指针或函数地址
    callfunc(plus, aa, bb);
    callfunc(minus, aa, bb);

    NEXTLINE

    return 0;
}

void f(int i, double j)
{
    printf("in f(), i = %d, j = %lf\n", i, j);
}


// 将函数作为参数传入其他函数  // 由于作为参数传入的函数的是指针，不带参数，所以参数需要额外传入
void callfunc(int (*fp)(int a, int b), int a, int b)
{
    printf("func_address:%p, return:%d\n", fp, (*fp)(a, b));
}

int plus(int a, int b)
{
    return a + b;
}

int minus(int a, int b)
{
    return a - b;
}


// 根据用户输入调用以下函数
void g(int a)
{
    printf("function:%s,result:%d", __func__, a);
}

void h(int a)
{
    printf("function:%s,result:%d", __func__, a + 1);
}

void j(int a)
{
    printf("function:%s,result:%d", __func__, a + 2);
}