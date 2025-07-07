#include <iostream>
#include "template.hpp"
using namespace std;

int main()
{
    // 模板在编译时会根据实际使用的类型生成对应的函数（实例化）。
    int a = 3, b = 2;
    swap_var(a, b); // 隐式实例化： 编译器根据调用时传入的参数类型自动推导 T。
    swap_var<int>(a, b); // 显式实例化： 直接在调用时指定 T 的具体类型。
    // swap_var<double>(a, b); // 报错，指定T的类型与传入参数不符
    cout << "a = " <<a << ", b = " << b << endl;

    double c = 1.2;
    // 如果模板参数列表只有一个参数，在函数中传入不同类型的参数，编译器就无法确定参数的类型
    // swap_var(a, c);

    cout << MyFunc::max(3.3, 2) << endl; // T 被推导为 double, S 被推导为 int
    cout << MyFunc::max(1, 3.2) << endl; // T 被推导为 int, S 被推导为 doubl

    // 类模板实例化必须显式指定类型
    MyVector<int> v(3);  // T 被指定为 int
    v[0] = 10;

    // 常量对象
    const MyVector<int> cv(3);
    int value = cv[0]; // 错误：若没有const版本的operator[]，此行无法编译

    return 0;
}
