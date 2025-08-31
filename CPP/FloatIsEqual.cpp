// 不建议直接使用==运算符判断两个float或double类型变量是否相等。\
因为浮点数在内存中以二进制形式存储，无法精确表示某些十进制小数（如 0.1），运算过程中会产生微小误差。
#include <iostream>
#include <cmath>  // 提供fabs函数（取绝对值）
using namespace std;

// 定义一个极小的阈值（根据精度需求调整）
const float EPS = 1e-6f;  // 10的-6次方

// 判断两个float是否相等
bool isEqual(float a, float b) {
    // 计算差值的绝对值，与阈值比较
    return fabs(a - b) < EPS;
}

int main() {
    // double a = 0.1f + 0.2f; // 编译器会提前优化
    // 使用double而不是float，精度问题更容易显现
    double x = 0.1f, y = 0.2f;
    double a = x + y;
    double b = 0.3f;

    // 避免直接使用==判断浮点数是否相等
    if (a == b) {
        cout << "相等" << endl;
        cout << "a = " << a << ", b = " << b << endl;
    } else {
        cout << "不相等" << endl;  // 实际会执行这里
        cout << "a = " << a << ", b = " << b << endl;  // 输出看似相同
    }
    
    // 判断两个浮点数是否相等，应检查它们的差值是否小于一个极小的阈值（通常称为「epsilon」）。\
    如果差值在阈值范围内，就认为它们相等。
    if (isEqual(a, b)) {
        cout << "相等" << endl;  // 现在会正确执行这里
        cout << "a = " << a << ", b = " << b << endl;
    } else {
        cout << "不相等" << endl;
        cout << "a = " << a << ", b = " << b << endl;
    }

    return 0;
}