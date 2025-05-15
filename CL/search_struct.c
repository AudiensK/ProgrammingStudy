#include <stdio.h>
// 线性搜索法搜索美分对应的名称；

/*
// 以下是用两个数组来实现这种搜索，但这两个数组是割裂的，这种结构对cache不友好;用hash table（散列表）更适合做这种搜索；
int amount[] = {1, 5, 10, 25, 50, 100};
char *name[] = {"penny", "nickel", "dime", "quarter", "half-dollar", "dollar"};
*/


// struct（结构体）能够把不同数据类型的变量组合成一个整体，从而表示一个更复杂的数据结构（例如，链表、树等数据结构）。
struct {  // 定义结构体  
    int  amount;
    char *name;
} coins[] = {  // 初始化
    {1, "penny"},
    {5, "nickel"},
    {10, "dime"},
    {25, "quarter"},
    {50, "half-dollar"},
    {100, "dollar"}
};

/*
int search(int key, int a[], int len)
{
    int ret = -1;
    for (int i = 0; i < len; i ++) {
        if (key == a[i]) {
            ret = i;
            break;
        }
    }
    return ret;
}
*/

int main()
{
    int k;
    printf("请输入金额：（美分）");
    scanf("%d", &k);

    // int r = search(k, amount, sizeof(amount) / sizeof(amount[0]));

    for (int i = 0; i < sizeof(coins) / sizeof(coins[0]); i ++) {
        if (k == coins[i].amount) {
            printf("%s\n", coins[i].name);
            break;
        } else {
            printf("输入无效");
        }
    }

    /*
    if (r > -1) {
        printf("%s\n", name[r]);
    } else {
        printf("输入无效");
    }
    */

    return 0;
}