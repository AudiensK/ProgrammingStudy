/* 枚举
枚举是一种用户定义的数据类型，它用关键字 enum 以如下语法来声明：
    enum 枚举类型名字 {名字0， ..., 名字n};
枚举类型名字通常不真的使用，要用的是大括号里的名字，
因为它们就是常量符号，它们的类型是 int ，值依次从0到n，如：
    enum color {red, yellow, green};
    这样就创建了三个常量，值分别是0，1，2
当需要一些可以排列起来的常量时，定义枚举的意义就是给这些常量值名字
*/

#include <stdio.h>

enum color {red, blue, yellow, green, purple, NumColors};
// 最后放一个NumColors用来表示有多少个枚举，需要遍历所有枚举量或者建立一个用枚举量做下标的数组就很方便了

/* 申明枚举量时可以指定值
enum color {red = 1, blue, yellow =5};  // red是1，跟在后面的blue就是2

枚举只是int，即使给枚举类型的变量赋不存在的整数值也没有warning或error
enum color t = 0;  // 在上面的枚举中，并没有值为0的枚举量

虽然枚举类型可以当作类型使用，但是实际上很少用不好用
如果有意义上排比的名字，用枚举比 const int 方便
枚举比宏（macro）好，因为枚举有int类型
*/

void f(enum color c);

//枚举量可以作为值；枚举类型可以跟上enum作为类型；实际上是以整数来做内部计算和外部输出的
int main()
{
    enum color t = red;
    printf("%d\n", t);

    scanf("%d", &t);
    f(t);

    return 0;
}

void f(enum color c)
{
    printf("%d\n", c);
}