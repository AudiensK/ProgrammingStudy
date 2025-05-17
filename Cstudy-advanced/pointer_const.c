#include <stdio.h>


void f(const int *p);

int main()
{
    // 指针是const，表示指针一旦得到了某个变量的地址，就不能再指向其他变量
    int i = 1;
    int j;
    int *const q = &i;  // q是cosnt，q不能被修改
    *q = 26;  // 可以和其他指针一样使用
    //q ++;  // 错误，因为指针q是const

    // 所指的是const，表示不能通过这个指针去修改这个变量（不能使那个变量成为const）
    const int *p = &i;  // *p不能被修改
    int const* p2 = &i;  // 等同于上一种写法,主要看*在const前还是后
    //*p = 26;  // 错误，不能通过p修改所指的变量的值
    i = 26;  // i仍然不是const
    p = &j;  // p可以做运算，可以指向其他变量

    f(&i);

    const int a[] = {1, 2, 3, 4, 5};
    // 数组变量已经是const的指针了,这里表示数组的每个单元都是const int
    // 这种写法必须通过初始化进行赋值。
    // 因为把数组传入函数传入的是数组的地址，所以函数内部可以修改数组单元的值
    // 为了保护数组不被破坏，可以设置参数为const，例如：
    //int sum(const int a[], int len);

    return 0;
}

// 可以把一个非const的值转换成const的
// 当要传递的参数的类型比地址大的时候，这是常用的手段；
// 既能用比较少的字节传递值给参数，又能避免函数对外面的变量的修改（比如传递一个数组结构）
void f(const int *p)
{
    //*p = 6;  // 传入指针所指向的值不能被修改
    printf("%d\n", *p);
}