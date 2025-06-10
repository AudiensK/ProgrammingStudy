#include <stdio.h>

void f(void)
{
    char word1[8];
    char word2[8];
    //scanf("%s", word1);  // 输入字符超过8个，输入会出现错误
    //scanf("%s", word2);
    scanf("%7s", word1);  // 在s前加上数字，限制最多输入多少字符
    // 前一个超过的字符会输入到后面一个scanf中，且直接跳过后面一个scanf的输入
    scanf("%7s", word2);  // 最后一个scanf中超出数量的字符会被直接舍弃
    printf("%s##%s##\n", word1, word2);
}

int main()
{
    f();

    /* 字符串输入输出
    char string[8];  // 8个字符的数组，最多接受7个字符，结束为0
    scanf("%s", string);
    printf("%s", string);

    scanf读入一个单词（到空格、tab或回车为止）
    scanf是不安全的，因为不知道要读入的内容长度

    常见错误
    char *string;  // 该指针还未初始化
    scanf("%s", string);  
    //char* string不是字符串变量，即使初始化指向一个字符串，也无法直接输入

    空字符串
    char buffer[100] = "";  //这是一个空字符串，buffer[0] = '/0'
    char buffer[] = "";  //这个数组长度只有1
    */

    return 0;
}