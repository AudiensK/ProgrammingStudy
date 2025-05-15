#include <stdio.h>

int main()
{
    int x;  // 不要输入过于大的整数，因为在计算机内存中，整数位数是有范围限制的。
    int n = 0;

    scanf("%d", &x);

    n++;
    x /= 10; 
    
    while (x > 0) {
        n++;
        x /= 10;        
    }

    printf("%d", n);

    return 0;
}