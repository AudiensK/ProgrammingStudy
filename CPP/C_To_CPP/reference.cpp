// 在 C++ 里，引用（Reference） 是一种特殊的变量，它充当另一个对象的别名。\
引用提供了一种间接访问对象的方式，允许函数或代码通过不同的名称操作同一个对象。

#include <iostream>

#define LOG(x) std::cout << x << std::endl;

void addone(int n);
void addtwo(int& n);
void addthree(int* n);
int& getElement(int arr[], int index);


int main()
{
    int num = 10;
    // int& number;  // 引用必须初始化
    int& number = num;  // number时num的引用（别名）

    std::cout << num << std::endl;
    number = 11;  // 对number的修改等同于修改num
    std::cout << num << std::endl;
    std::cout << number << std::endl;

    // 指向同一块内存
    std::cout << &num << std::endl;
    std::cout << &number << std::endl;

    addone(number);
    std::cout << num << std::endl;

    addtwo(number);
    std::cout << num << std::endl;

    addthree(&number);  // 引用参数允许函数修改实参
    std::cout << num << std::endl;

    // 引用必须始终指向一个有效的对象，不能指向 nullptr。
    int* ptr = nullptr;  // 合法：空指针
    // int& ref = nullptr;  // 错误：引用不能为null

    // 函数可以返回引用，允许调用者修改原始对象。
    int arr[10] = {};
    getElement(arr, 0) = 100;  // 直接修改数组的第一个元素
    LOG(arr[0])

    // 使用 const 修饰的引用可以绑定到常量对象或临时对象，防止修改。
    const int& ref = 42;  // 合法：常量引用可以绑定到临时对象
    // ref = 52;  // ref为const

    return 0;
}


void addone(int n)
{
    n++;
}

// 通过引用传递参数，函数可以直接操作原始数据，避免复制开销。
void addtwo(int& n)
{
    n += 2;
}

void addthree(int* n)
{
    *n += 3;
}

// 函数可以返回引用，允许调用者修改原始对象。
int& getElement(int arr[], int index)
{
    return arr[index];  // 返回数组元素的引用
}