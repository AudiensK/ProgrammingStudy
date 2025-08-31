#include <iostream>
#include <random>  // 现代随机数库
#include <chrono>  // 用于获取时间种子
#include <iterator> // 包含 std::size


void bubble_sort(int arr[], const int size);
void bubble_sort_refined(int arr[], const int size);


int main()
{
    // 获取当前时间作为随机数种子
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // 选择随机数引擎（如mt19937，一种高性能梅森旋转算法）
    std::mt19937 generator(seed);
    
    // 定义分布范围 [1, 100]
    std::uniform_int_distribution<int> distribution(1, 100);

    int size = -1;
    std::cout << "输入数组大小（1-100）生成随机数组：" << std::endl;
    while (1)
    {
        std::cin >> size;
        if (size < 1 || size > 100)
        {
            std::cout << "数组大小超出规定范围，请重新输入：" << std::endl;
        } else 
        {
            break;
        }
    }

    std::cout << "\n生成的随机数组为：\n";
    int arr_int[size];
    for (int i = 0; i < size; i ++)
    {
        arr_int[i] = distribution(generator);

        std::cout << arr_int[i];

        if (i != size -1)
        {
            std::cout << " ";
        } else 
        {
            std::cout << "\n";
        }

        if ((i + 1) % 10 == 0 && i != size -1)
        {
            std::cout << "\n";
        }
    }


    int sorted_arr[size];
    for (int i = 0; i < size; i ++)
    {
        sorted_arr[i] = arr_int[i];
    }

    // bubble_sort(sorted_arr, size);
    bubble_sort_refined(sorted_arr, size);


    std::cout << "\n按升序排序后的数组为：" << std::endl;
    for (int i =0; i < size; i ++) 
    {
        std::cout << sorted_arr[i];

        if (i != size -1)
        {
            std::cout << " ";
        } else 
        {
            std::cout << "\n";
        }

        if ((i + 1) % 10 == 0 && i != size -1)
        {
            std::cout << "\n";
        }
    }

    return 0;
}

void bubble_sort(int arr[], const int size)
{
    int change = 0;
    int i = 0;
    while (1)
    {
        if (i == size - 1) 
        {
            if (change == 0) {
                break;
            } else {
                i = 0;
                change = 0;    
            }

        }

        int t;
        if (arr[i] > arr[i + 1]) 
        {
            t = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = t;
            change ++;
        }
        i ++;
    }
}

void bubble_sort_refined(int arr[], const int size)
{
    for (int i = 0; i < size - 1; i ++) {
        bool swapped = false;
        for (int j = 0; j < size - 1 -i; j ++) { 
        // 最大的数始终会被交换到最后，因此可以通过j < size - 1 -i减少不必要的比较
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}