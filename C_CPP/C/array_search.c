#include <stdio.h>

// 找到key在数组中的位置，key要寻找的数字，a要寻找的数组，length数组的长度;
// 找到则返回其在a中的位置，没找到返回-1;
int search(int key, int a[], int length);

int main()
{
    int a[] = {2, 4 ,5, 6, 7, 8, 10, 14, 17, 19, 25, 31, };
    int x;
    int loc;
    printf("请输入一个整数：");
    scanf("%d", &x);

    loc = search(x, a, sizeof(a)/sizeof(a[0]));
    if (loc != -1) {
        printf("%d在数组a中的第%d个位置上。\n", x, loc + 1);
    } else {
        printf("未找到%d在数组a中的位置。\n", x);
    }

    return 0;
}

int search(int key, int a[], int length)  
// 数组作为函数参数时，往往必须再用另外一个参数来传入数组大小（指针相关，会导致结果出错）；
// 数组作为函数参数时，不能在[]中给出数组大小，不能再利用sizeof来计算数组的元素个数。
{   
    int ret = -1;
    int i;
    for (i = 0; i < length; i ++) {
        if (a[i] == key) {
            ret = i;
            break;
        }
    }
    return ret;
}