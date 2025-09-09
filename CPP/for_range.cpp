#include <iostream>
#include <vector>
#include <string>

int main()
{
    int numbers[] = {1, 2, 3, 4, 6, 7};

    // 基于范围的for循环（C++11）,提供了更简洁的遍历容器元素的方式。
    for(auto number: numbers) // auto 是C++11引入的关键字，用于自动类型推导。编译器会根据初始化表达式自动推断变量的类型。
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // 使用引用可以直接修改原数组元素
    for(auto &number : numbers) {
        number *= 2; // 每个元素乘以2
    }
    
    for(auto number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // 使用const引用（避免拷贝，只读访问）
    std::vector<std::string> words = {"hello", "world", "c++"};
    
    // 使用const引用，避免字符串拷贝
    for(const auto &word : words) {
        std::cout << word << " ";
    }
    // 输出: hello world c++

    return 0;
}