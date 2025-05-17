// 1.生成一个用户指定大小为n且n<100的随机正整数数组a[n]，要求数组内所有元素都小于200，输出a[n]；
// 2.对a[n]进行排序，从小到大，且使用选择排序法，不能使用qsort,输出排序后的a[n]；
// 3.用户输入正整数x，查询x在排序后的a[n]中的位置（下标），输出下标值。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_num(void);
void order_array(int a[], int len);
int search(int key, int a[], int len);


int main()
{   
    int n = 0;
    int x = 0;

    srand(time(0));  // 初始化随机数种子

    printf("请输入数组的大小：");
    scanf("%d", &n);
    if (n > 0 && n <= 100) {  // 判断用户输入是否有效
        // 初始化随机数组a[n]
        int a[n];  

        printf("排序前数组：\n");
        for (int i = 0; i < n; i ++) { 
            a[i] = rand_num();;
            printf("%d ", a[i]);  // 输出排序前的数组
        }

        // 排序
        int len = sizeof(a) / sizeof(a[0]);
        order_array(a, len);

        printf("\n排序后的数组：\n");
        for (int i = 0; i < len; i ++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        // 查询
        printf("\n请输入要查询的数：");
        scanf("%d", &x);
        int ret = search(x, a, len);
        if (ret < 0) {
            printf("您查询的数不在该数组中。\n");
        } else {
            printf("您查询的数在该数组中的索引为%d。\n", ret);
        }

    } else {
        printf("输入无效，程序结束。");
    }
    
    return 0;
}


int rand_num(void)  // 获取小于200的随机整数
{
    int ret;
    do {
        ret = rand() % 200;
    } while (ret <= 0 || ret >= 200);    

    return ret;
}


void order_array(int a[], int len)  // 使用选择排序法给整数数组从小到大排序
{
    for (int i = len - 1; i > 0; i --) {
        int maxid = 0;  // 求待排序最大元素的下标
        for (int _i = 1; _i < i + 1; _i ++) {
            if (a[_i] >= a[maxid]) {
                maxid = _i;
            }
        }
        // 将最大值与待排序元素最后一位交换
        int t = a[i];
        a[i] = a[maxid];
        a[maxid] = t;
    }
}

int search(int key, int a[], int len)  // 二分法查询key在数组中的位置，并返回下标值，返回-1表示key不在该数组中
{
    int ret = -1;
    int left = 0;
    int right = len - 1;
    int mid = (left + right) / 2;
    while (left != mid || mid == 0) {
        if (key == a[mid]) {
            ret = mid;
            break;
        } else if (key > a[mid]) {
            left = mid;
            mid = (mid + right) / 2;
        } else {
            right = mid;
            mid = (mid + left) / 2;
        }
    }

    return ret;
}

