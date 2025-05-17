/* 字符串数组
char **a;  // a是一个指针，指向另外一个指针，那个指针指向字符（串）
    char *fruits[] = {"apple", "banana", "cherry"};
    char **a = fruits;  // a 指向 fruits 数组的第一个元素（"apple" 的地址）
    
char *a[];  // 字符串数组
    相当于定义一个指针数组，数组中每个元素指向一个字符（串）数组

char a[][10];  // 是一个二维数组，第二维必须有确定大小，否则编译不通过（错误写法a[][]）
*/

#include <stdio.h>

int main()
{
    int type = 0;

    do {
        printf("请输入类型（1、2、3、4、5）:");
        scanf("%d", &type);
    } while (type > 5 || type < 1);

    char *a[] = {"你好", "早上好", "晚上好", "再见", "？？"};
    //char **a = {"你好", "早上好", "晚上好", "再见", "什么？"};  // 编译报错

    printf("%s\n", a[type - 1]);

    // switch (type) {
    //     case 1:
    //         printf("你好"); 
    //         break;  
    //     case 2:
    //         printf("早上好");
    //         break;
    //     case 3:
    //         printf("晚上好");
    //         break;
    //     case 4:
    //         printf("再见");
    //         break;
    //     default:
    //         printf("什么？");
    //         break;
    // }
    
    return 0;
}