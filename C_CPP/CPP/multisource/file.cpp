#include <iostream>
#include "myhead.h"

int a = 10;
int b = 7;

void log1(int a)
{
    std::cout << a << std::endl;
}

void log2(int a)
{
    std::cout << a << std::endl;
}

void MyClass1::log3() 
{
    std::cout << a << std::endl;
}