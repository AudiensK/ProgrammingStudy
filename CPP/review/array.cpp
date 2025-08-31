#include <iostream>

int main()
{
    double weights1[5] = {0};
    double weights2[5] = {};
    double weights3[5] = {3.1, 2.3, 3.4};
    double weights4[] = {4.1, 2.3, 3.4, 4.5, 5.6};

    // c++11数组的列表初始化方式，省去一个等号
    double weights5[5]{5.1, 2.3, 3.4, 4.5, 5.6};

    double* weights = nullptr;
    int i = 5;
    switch(i) {
        case 1:
            weights = weights1;
            break;
        case 2:
            weights = weights2;
            break;
        case 3:
            weights = weights3;
            break;
        case 4:
            weights = weights4;
            break;
        case 5:
            weights = weights5;
            break;
        default:
            weights = weights1;
    }

    for (int i = 0; i < 5; i++) {
        std::cout << *(weights + i) << " ";
        if (i == 4) {
            std::cout << std::endl;
        }
    }
    
    return 0;
}