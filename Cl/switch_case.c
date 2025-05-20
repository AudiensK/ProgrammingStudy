#include <stdio.h>

int main()
{
    int type = 0;

    scanf("%d", &type);

    /*
    if (type = 1)
        printf("你好");
    else if (type = 2)
        printf("早上好");
    else if (type = 3)
        printf("晚上好");
    else if (type = 4)
        printf("再见");
    else
        printf("什么？");
    */

    // 等同于上面写法，但是switch-case会判断后直接跳转至相应的常量处，if-else则需要从开头往后逐步判断。
    switch (type) {  // switch(控制表达式){  // 控制表达式只能是整数型结果
        case 1:  // case 常量：
            printf("你好"); 
            break;  
            /* switch 判断常量后会直接跳转到对应的case执行后面的语句，遇到break后跳出switch-case，
            如果没有遇到break,则会进入下一个case，直到遇到break，或switch结束为止。*/
        case 2:
            printf("早上好");
            break;
        case 3:
            printf("晚上好");
            break;
        case 4:
            printf("再见");
            break;
        default:
            printf("什么？");
            break;
    }
    
    return 0;
}