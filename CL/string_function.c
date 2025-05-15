#include <stdio.h>
#include <string.h>  // 符串处理函数需要包含string.h头文件
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /* 
    strlen
    size_t strlen(const char *s);  
        // 参数加上const表明该函数不会修改传入的字符串内容  
        // size_t是返回值类型，一种无符号整数类型，通常用于表示对象的大小或者数组的长度。
    返回字符串s的长度（不包括结尾的0）。
    */
    char line[] = "Hello World!";
    printf("strlen(line)=%lu\n", strlen(line));
    printf("sizeof(line)=%lu\n", sizeof(line));

    /* 
    strcmp  // cmp是compare的简写
    int strcmp(const char *s1, const char *s2);
    比较两个字符串，返回：
        0: s1 == s2
        1: s1 > s2
        -1: s1 < s2
    */
    char s1[] = "abc";
    //char s2[] = "abc";  // 0
    //char s2[] = "bbc";  // -1
    //char s2[] = "Abc";  // 1
    char s2[] = "abc ";  // -1
    printf("%d\n", strcmp(s1, s2));
    //printf("%d\n", s1 == s2);  // 这种写法错误，因为数组比较的是地址，所以永远是0(false)，

    /* 
    strcpy  // copy
    char * strcpy(char *restrict dst, const char *restrict scr);
    把src的字符串拷贝到dst
        restrict表示src和dst不重叠（C99）
    返回dst
    dst必须有足够空间

    复制一个字符串
    char *a = (char*)malloc(strlen(src) + 1);  // 注意别忘记+1，因为strlen得到的结果不包含'\0'
    strcpy(dst, src);
    free(a)
    */
    
    /*
    strcat
    char *strcat(char *restrict s1, const char *restrict s2);
    把s2拷贝到s1后面，连接成一个长的字符串
    返回s1
    s1必须有足够空间    
    */

    // strcpy和strcat都可能出现安全问题，因为无法知道拷贝到的数组空间是否足够，尽量避免使用这两函数
    // 更安全的版本是在中间加个n
    // char * strncpy(char *restrict dst, const char *restrict scr, size-t n);
    // char *strncat(char *restrict s1, const char *restrict s2, size-t n);
    
    // int strncmp(const char *s1, const char *s2, size-t n);  // 比较前n个字符

    /* 字符串中找字符
    char* strchr(const char*s, int c);  // 从左往右
    char* strrchr(const char*s, int c);  // 从右往左
    返回的是指针，返回NULL表示没找到
    */
    char h[] = {"Hello"};
    char *p = strchr(h, 'l');
    //char *p = strrchr(h, 'l');
    p = strchr(p+1, 'l');
    printf("*p=%c\n", *p);
    printf("p=%p\n", p);
    printf("p=%s\n", p);
    char *t = (char*)malloc(strlen(p) + 1);
    strcpy(t, p);
    printf("t=%s\n", t);
    int c = *p;
    *p = '\0';
    char *t1 = (char*)malloc(strlen(h));
    strcpy(t1, h);
    *p = c;
    printf("%s\n", t1);
    free(t);
    free(t1);

    /* 字符串中找字符串
    char* strstr(const char *s1, const char *s2);  
    char* strcasestr(const char *s1, const char *s2);  // 忽略大小写
    */

    return 0;
}