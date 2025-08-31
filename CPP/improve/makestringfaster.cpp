#include <iostream>
#include <string>
#include <stdint.h>

static uint32_t s_AllocCount = 0;

void* operator new(size_t size) // 返回void*类型指针
{
    s_AllocCount++;
    std::cout << "Allocating " << size << "bytes\n";
    return malloc(size);
}

void PrintString(const std::string& str)
{
    std::cout << str << std::endl;
}

int main()
{
    std::string astring = "1234567890123456789012 1234567890123456789012";
    
    // PrintString(astring);

#if 1
    std::string firstName = astring.substr(0, 22);
    std::string lastName = astring.substr(23, 45);
#else
    std::string_view firstName(astring.c_str(), 22);
    std::string_view lastName(astring.c_str() + 23, 45);
#endif

    std::cout << s_AllocCount << " allocations" << std::endl;

    // std::cin.get();
}