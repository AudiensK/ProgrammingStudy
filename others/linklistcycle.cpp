// 快慢指针法判断链表中是否有循环
#include <iostream>
using std::cout, std::cin;

int main()
{
    int size = 100; // 设置数组大小
    if (size < 1) {
        size = 1;
    }
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    int cycle_point = 32; // 设置循环点
    if (cycle_point > size || cycle_point < 1) {
        cycle_point = size;
    }
    int max_search_cnt = 1000;
    int cycle_cnt = 0;
    int index = 0;
    int f = 0;
    int cycle = 0;
    do {
        cout << "arr[" << index << "] = " << arr[index] << "\n";
        cout << "f = " << f << "\n";
        index++;
        if (index >= size) {
            index = cycle_point - 1;
        }

        f += 2;
        while (f >= size) {
            f -= size + cycle_point - 1;
        }

        cycle_cnt++;

        if (cycle_cnt > max_search_cnt) {
            cout << "cycle_cnt > max_search_cnt\n";
            cycle = 1;
        } else if (index == f && cycle_cnt > 1) {
            cycle = 1;
            cout << "cycle_cnt = " << cycle_cnt << "\n";
        }

        if (f >= size) {
            cycle = 0;
            break;
        }
    } while (!cycle);


    if (cycle) {
        cout << "true\n"; 
    } else {
        cout << "false\n";
    }

    return 0;
}