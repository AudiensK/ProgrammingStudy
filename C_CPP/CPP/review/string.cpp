#include <iostream>
#include <string>

int main()
{
    std::string s1("hello");
    std::string s2 = "hello";
    std::string s3 = {'h', 'e', 'l', 'l', 'o', '\0'}; // 使用std::string不必要显式包含终止符'\0'
    std::string s4 = {'h', 'e', 'l', 'l', 'o'};

    std::cout << s1 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl; // 输出时遇到终止符会停止输出，因此显示结果一样

    std::cout << (s1 == s2) << std::endl;
    std::cout << (s1 == s4) << std::endl;
    std::cout << (s3 == s4) << std::endl; // 终止符也被视作一个字符，长度也不一致，因此不相等

    std::cout << s3.size() << std::endl; // 终止符也被视作一个字符，因此长度为6
    std::cout << s4.size() << std::endl;

    return 0;
}