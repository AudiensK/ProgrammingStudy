#include <stdio.h>

int main()
{
    // 混合输入
    int a;
    char b;

    scanf("%d %c", &a, &b);  // 读到%d后要读到空格后再读到%c
    //scanf("%d%c", a, b); 
    printf("a=%d,b=%d,b='%d'\n\n", a, b, b);

    // 字符运算
    int c = 'A';
    c++;
    printf("%c\n\n", c);

    /*  大小写转换
    字母在ASCII表中是顺序排列，大小写字母是分开排列，大写在前，小写在后
        'a'-'A' 可以得到两段之间的距离（负值）
        a +'a'-'A'可以把大小字母变成小写
        a + 'A'-'a'可以把小写字母变成大写
    */ 
   int letter = 'C';
   letter += 'a'-'A';
   printf("%c\n", letter);
   letter -= 'a'-'A';
   printf("%c\n", letter);

    return 0;
}
