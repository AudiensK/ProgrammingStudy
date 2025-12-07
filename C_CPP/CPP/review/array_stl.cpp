#include <iostream>
#include <array>

int main(void)
{
    std::array<char, 10> arr01 = {'H', 'e', 'l', 'l', 'o'};

    for (char c: arr01)
    {
        std::cout << c;
    }

    std::cout << std::endl;

    for (int i = 0; i < arr01.size(); ++i)
    {
        std::cout << arr01[i];
    }

    std::cout << "\n" << arr01.size();

    return 0;
}