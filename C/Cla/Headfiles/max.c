#include "max.h"

int gAll = 11;  // 可以通过在头文件中声明来让其他文件使用这个文件的全局变量

// 不对外公开的函数
// 在函数前面加上static就使得它成为只能在所在的编译单元中被使用的函数
// 在全局变量前面加上static就使得它成为只能在所在的编译单元中被使用的全局变量
static double PI = 3.1415926;

static double round_long(int d)
{
    return PI * d;
} 


double max(int a, int b)
{
    // int max;
    // if (if_abtb(a, b)) {
    //     max = a;
    // } else {
    //     max = b;
    // }

    // return max;
    a = round_long(a);

    return a>b?a:b;
    // 三元运算符（Ternary Operator）或条件表达式（Conditional Expression），
    // 是一种简洁的条件判断语法。它允许你根据一个条件的真假来选择两个值中的一个，功能类似于简化版的if-else语句。
    // 条件表达式 ? 值1 : 值2;如果条件表达式为真（非零），则整个表达式的值为值1。如果条件表达式为假（零），则整个表达式的值为值2。
    // 三元运算符的优先级较低，使用时需注意括号：int result = (a > b) ? a : (b + 1);
}

bool if_abtb(int a, int b)
{
    if (a > b) {
        return true;
    } else {
        return false;
    }
}