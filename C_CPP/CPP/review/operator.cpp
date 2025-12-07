// 运算符 Operator
/*
赋值运算符
=
优先级较低，从右到左
int a, b;
a = b = 3; // 先b = 3, 再a = b;

算数运算符（二元运算符）
+  -  *  /  %
加 减 乘 除 模
各个运算符优先级顺序同数学运算，先乘除，后加减

关系运算符
== 等于
!= 不等于
> 大于
< 小于
>= 大于等于
<= 小于等于

逻辑运算符
！  &&  ||
非  与  或

复合赋值运算符
+= -= *= /= %= >>= <<= &= ^= |=

增量\减量运算符
++ --
后缀比前缀性能消耗稍大一些，更推荐前缀方式使用

条件运算符(三元运算符)
?
条件 ? 结果1 : 结果2
满足条件返回结果1，不满足返回结果2

位运算符（注意与逻辑运算符的区别）
& | ...... ~ << >>

左移右移运算符
（重载后）插入提取运算符，用于输入输出
cout << "Hello";
cin >> a;

类型转换运算符
int a;
float b = 1.12345
a = (int)b // 强制转换为int类型
a = int(b) // 另外一种写法

*/

#include <iostream>
#include <bitset>


int main()
{
    int a1 = 3, a2 = 3;
    int b, c;
    b = a1++; // 后缀，先赋值，后增减量
    c = ++a2; // 前缀，先增减量，后赋值
    std::cout << "a1 = " << a1 << ", b = " << b << std::endl;
    std::cout << "a2 = " << a2 << ", c = " << c << std::endl;

    a1 = b == c ? 5 : 6; // b == c 为 false
    std::cout << "a1 = " << a1 << "\n";
    a2 = b < c ? 5 : 6; // b < c 为 true
    std::cout << "a2 = " << a2 << "\n";

    int b1 = 0b101011;
    int b2 = 0b100110;
    std::cout << "b1 & b2 = " <<  std::bitset<6>(b1 & b2) << std::endl; // 与
    std::cout << "b1 | b2 = " <<  std::bitset<6>(b1 | b2) << std::endl; // 或
    std::cout << "b1 ^ b2 = " <<  std::bitset<6>(b1 ^ b2) << std::endl; // 异或
    std::cout << "    ~b1 = " <<  std::bitset<6>(~b1) << std::endl; // 取反

    int b3 = 6;
    std::cout << "         6 = 0b" << std::bitset<8>(b3) << std::endl;
    std::cout << "    6 << 2 = 0b" << std::bitset<8>(6 << 2) << std::endl; // 向左移动两位，空出位置补零
    std::cout << "    6 >> 1 = 0b" << std::bitset<8>(6 >> 1) << std::endl; // 向右移动两位，空出位置补零
    std::cout << "0b100 >> 1 = 0b" << std::bitset<8>(0b100 >> 1) << std::endl;


    return 0;
}