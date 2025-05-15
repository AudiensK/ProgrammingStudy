#include <stdio.h>
#include <string.h>

int main()
{
    int x;
    double sum = 0;
    int cnt = 0;

    {
        // 创建一个包含5个整数的数组，并初始化为0
        int arr1[5] = {0};

        // 创建一个包含5个整数的数组，并进行部分初始化
        int arr2[5] = {1, 2}; 

        // 创建一个包含3个整数的数组，并完全初始化
        int arr3[3] = {1, 2, 3};

        // 创建一个包含5个整数的数组，并进行部位指定位置的初始化
        int arr4[5] = {[1]=3, [4]=7};

        // 数组大小由初始化列表确定
        int arr5[] = {1, 2, 3, 4, 5};

        // 数组不能直接赋值给另外一个变量，需要遍历每个元素，或者使用memcpy函数（#include <string.h>）；
        // int arr6[] = arr5; 错误的
        const int SIZE = 5;
        int arr6[SIZE];
        memcpy(arr6, arr5, sizeof(arr1));  // 将arr5的内存内容复制到arr6，sizeof(arr1)表示要复制的字节数。

        for (int i=0; i < sizeof(arr2)/sizeof(arr2[0]); i ++) {  // sizeof(a)/sizeof(a[0]) 得到数组中元素的数量
            printf("%d ", arr2[i]);
        }
        printf("\n");
    }
        

    // 数组是一种容器，其中所有元素具有相同数据类型，一旦创建则不能改变其大小，数组中元素在内存中是连续依次排列的。
    int number[100];  // 定义数组：类型 变量[元素数量]，元素数量必须为整数；
    // c99以前元素数量必须是编译时确定的字面量，c99以后可以是变量，但是数组一旦创建好了就不可改变其大小。

    scanf("%d", &x);
    while ( x != -1 ) {
        number[cnt] = x;  // 对数组中元素赋值。
        // 数组中的每个单元（如a[0]、a[3]等）就是数组类型中的一个变量；
        // 使用数组时放在[]中的数字叫做下标或索引，从0开始计数。
        /*  
        有效的下标范围
        1、编译器和运行环境都不会检测数组下标是否越界，无论是对数组单元做读还是写；
        2、一旦程序运行，越界的数组访问可能造成问题，导致程序崩溃，比如segmentation fault；
           也可能运气好不出现问题或没造成严重后果（很多时候程序出现问题可能是下标越界或指针问题）；
        3、程序编写者有责任确保程序只使用有效范围的下标值：[0,数组大小-1]。
        */

        sum += x;
        cnt ++;
        scanf("%d", &x);
    }

    if ( cnt > 0 ) {
        int i = 0;
        double average = sum / cnt;

        // 遍历数组
        for ( i = 0; i < cnt; i++) {
            if ( number[i] > average ) {  // 使用数组
                printf("%d ", number[i]);
            }
        }
    }

    return 0;
}