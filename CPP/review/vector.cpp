#include <iostream>
#include <vector>

int main()
{
    std::vector<double> vec01 = {1.3, 2.4, 3.5};

    for (double num : vec01)
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < vec01.size(); ++i)
    {
        std::cout << vec01[i] << " ";
    }

    return 0;
}