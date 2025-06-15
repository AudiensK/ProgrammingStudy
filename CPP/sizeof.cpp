#include <iostream>

int main()
{
    // sizeof是一种运算符
    std::cout << "sizeof(char)=" << sizeof(char) << " Byte" << std::endl;
    std::cout << "sizeof(wchar_t)=" << sizeof(wchar_t) << " Byte" << std::endl;

    std::cout << "sizeof(bool)=" << sizeof(bool) << " Byte" << std::endl; 

    std::cout << "sizeof(int)=" << sizeof(int) << " Byte" << std::endl;
    std::cout << "sizeof(short)=" << sizeof(short) << " Byte" << std::endl;
    std::cout << "sizeof(long)=" << sizeof(long) << " Byte" << std::endl;
    std::cout << "sizeof(long long)=" << sizeof(long long) << " Byte" << std::endl;

    std::cout << "sizeof(float)=" << sizeof(float) << " Byte" << std::endl;
    std::cout << "sizeof(double)=" << sizeof(double) << " Byte" << std::endl;
    std::cout << "sizeof(long double)=" << sizeof(long double) << " Byte" << std::endl;

    std::cout << "sizeof(void)=" << sizeof(void) << " Byte" << std::endl;

    std::cin.get();
    return 0;
}