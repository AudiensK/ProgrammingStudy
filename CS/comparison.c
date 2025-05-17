#include <stdio.h>

int main()  // 关系运算结果只能为0或1，关系运算符可以参与数学运算，优先级很低，但是比赋值运算高，例如：7 >= 3+4  ； int c = 5< 0
{
    printf("%d\n", 5 == 3);
    printf("%d\n", 5 > 3);
    printf("%d\n", 5 <= 3);

    return 0;
}