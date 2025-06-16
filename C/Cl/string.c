#include <stdio.h>


int main()
{
    // 字符数组
    char a[] = {'H', 'e', 'l', 'l', 'o', '!'};
    // 字符串  最后一个单元以'\0'或0结尾
    char b[] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
    printf("sizeof(a)/sizeof(a[0])=%d\n", sizeof(a)/sizeof(a[0]));
    printf("sizeof(b)/sizeof(b[0])=%d\n", sizeof(b)/sizeof(b[0]));
    printf("sizeof(b)=%zu\n", sizeof(b));
    // 由于字符只有1字节，所以sizeof(str)与sizeof(str)/sizeof(str[0])相等
    // 以下写法会出错，只会显示最后一个字符
    //char c = 'word'; 
    //printf("%c\n", c);

    /* 字符串
    C语言的字符串是以字符数组形式存在的
        不能用运算符对字符串做运算
        通过数组的方式可以遍历字符串
    字符串字面量可以用来初始化字符字符数组   
    */

    /*  
    以0（整数0）结尾的一串字符
        0和'\0'是一样的，但是和'0'不一样
    0标志着字符串的结束，但它不是字符串的一部分
        计算字符串长度时不包含这个0，strlen(str)计算 
        // 但是0在内存中占用一个字节，用sizeof(str)计算
    字符串以数组形式存在，以数组或指针的形式访问
        更多的是以指针形式
    string.h里面有很多处理字符串的函数
    */

    // 字符串变量
    char *str = "Hello";
    char word[] = "Hello";
    char line[10] = "Hello";  // 5个字符，在数组中占据6个字节，因为最后还有个0
    //printf("*str=%s\n", *str);  // 运行会报错
    // 因为str 是一个指向字符串常量 "Hello" 首字符的指针，*str即为字符H，用 %s 来输出 *str 会引发错误
    printf("*str=%c\n", *str);
    //printf("*str=%s\n", *str);  // 运行时报错
    printf("str=%s\n", str);
    char *str1 = "H";  // str指向的时字符串
    printf("str1(%%c)=%c\n", str1);  // %c与str1类型不匹配，导致未定义行为，输出结果错误，不同环境结果可能不同

    // 字符串常量（字面量）
    /*  "Hello"  用双引号括起来
        "Hello"会被编译器变成一个字符数组放在某处，这个数组长度是6，结尾还有表示结束的0
        两个相邻的字符串常量会被自动连接起来
    */
    printf("\"Hello "
        "World!\"\n");  // 两个相邻字符串常量自动连接
    printf("Hello \
World!\n");  // 用反斜杠\表示连接下一行
    printf("Hello\
        World!\n");  // 反斜杠\换行连接的字符串字面量需要注意两行之间的空格

    printf("sizeof(*str)=%zu\n", sizeof(*str));  // 指针指向第一个字符，所以是1字节（byte）
    printf("sizeof(word)=%zu\n", sizeof(word));  // word是字符串，以0结尾，所以6字节
    printf("sizeof(line)=%zu\n", sizeof(line));  // line长度为10
    printf("sizeof(\"Hello\")=%zu\n", sizeof("Hello"));  // "Hello"是字符串常量，以0结尾，所以6字节

    /*  字符串常量
    char *s = "Hello World!";  
    "Hello World!"是在编译时已有的，所以编译器把它放在一个只读的位置，即作为常量
    s是一个指针，初始化指向一个字符串常量：
        由于是常量，所以实际上s是const char *s，不过编译器接受不带const的写法；
        试图对s所指向的字符串做写入会导致严重的后果。
    如果需要修改字符串，应该用数组：
        char s[] = "Hello World!";
    */
    char *s = "Hello World!";
    //s[0] = 'B';  // 编译不会报错，但是运行时会出错
    char *s2 = "Hello World!";
    int i = 0;
    // s和s2指向同一个地址，且地址很大，位于程序的代码段，而且时只读
    printf("s=%p\n", s);
    printf("s2=%p\n", s2);
    // 通过获取i的地址对比，可以发现字符串s和s2的地址明显大于变量i
    // 不同编译器、操作系统可能不一样，有的常量储存在很小地址的内存中
    // 通常来说栈区位于高地址，常量区位于低地址；
    printf("&i=%p\n", &i);

    char s3[] = "Hello World!";
    s3[0] = 'B';
    // s3地址在本地变量这里，不是直接指向"Hello World!"字符串常量，相当于由字面量拷贝到本地变量，所以可以直接修改字符串
    printf("s3=%p\n", s3);  // 由于s3是数组，所以等同于printf("&s3=%p\n", &s3);
    printf("s3[0]=%c\n", s3[0]);
    printf("s3=%s\n", s3);
    printf("*s3=%c\n", *s3);
    printf("'\\0' == %d != '0'\n", '\0');  // '\0' == 0 != '0'

    /*  指针还是数组？
    char *str = "Hello World!";
        作为指针这个字符串不知道在哪里，用于作为参数处理，和做动态分配空间
        如果需要处理一个字符串，用指针
    char str[] = "Hello World!";
        作为数组这个字符串就在这里，作为本地变量空间自动被回收
        如果需要构造一个字符串，用数组
    */

    /* 
    char*不能简单的说就是字符串
    字符串可以表达为char*的形式
    char*不一定是字符串，本意是指向字符的指针，可能是指向字符的数组（如int*），只有它指向的数组结尾是0，才能说是字符串
    */

    // 字符串初始化
    char *c1 = "title";
    char *c2;
    printf("c2=%p\n", c2);  // 未初始化前，指向了一个随机地址
    printf("&c2=%p\n", &c2);
    // 并没有产生新的字符串，只是让c2指向c1所指的字符串
    c2 = c1;
    printf("c1=%p\nc2=%p\n", c1, c2); 
    printf("\n"); 

    //
    char string[] = "Hello";
    i = 0;
    printf("string[i] = %c\n", *(string + i));  // *(string + i)相当于string[i]
    printf("string[i] = %c\n", string[i]);
    // string = "World";  // 不能直接赋值
    // 需要逐个单元赋值或使用strcpy()

    return 0;
}