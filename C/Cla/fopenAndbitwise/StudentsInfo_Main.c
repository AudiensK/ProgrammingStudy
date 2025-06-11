// 二进制读写
// size_t fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
// size_t fwirte(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
// void *restrict ptr 读写的那块内存的指针，size_t size 这块内存的大小，size_t nitems 有几个这样的内存
// FILE *restrict stream 文件指针；注意FILE指针是最后一个参数
// 返回的是成功读写的字节数

// 为什么要传入nitems
// 因为二进制文件的读写一般都是通过对一个结构变量的操作来进行的
// 于是nitems就是用来说明这词读写几个结构变量

#include <stdio.h>
#include "student.h"

void getList(Student aStu[], int number);
int save(Student aStu[], int number);

int main(int argc, char const *argv[])
{
    int number = 0;
    printf("输入学生数量：");
    scanf("%d", &number);
    Student aStu[number];

    getList(aStu, number);
    if (save(aStu, number)) {
        printf("保存成功\n");
    } else {
        printf("保存失败\n");
    }

    return 0;
}


void getList(Student aStu[], int number)
{
    char format[STR_LEN];  // 创建一个字符数组，用于存放名字
    sprintf(format, "%%%ds", STR_LEN - 1);  // 输出结果为"%19s"
    // sprintf向字符串输出，%%转义为%，%d输出整数，即参数STR_LEN - 1

    int i;
    for ( i=0; i<number; i++) {
        printf("第%d个学生：\n", i+1);
        printf("\t姓名：");  // \t 在文本中插入一个制表符，可以更方便地控制文本对齐
        scanf(format, aStu[i].name);  // name是字符数组，因此aStu[i].name是个指针，不需要用&取址
        // 由于format为"%19s"，以上写法相当于scanf(%19s", aStu[i].name);
        printf("\t性别（0-男，1-女，2-其他）：");
        scanf("%d", &aStu[i].gender);  // 注意别忘了&
        printf("\t年龄（岁）：");
        scanf("%d", &aStu[i].age);  // 注意别忘了&
    }
}


int save(Student aStu[], int number)
{
    int ret = -1;
    FILE *fp = fopen("student.data", "wb");  // wb二进制写入
    if (fp) {
        ret = fwrite(aStu, sizeof(Student), number, fp);  // aStu相当于&aStu[0]
        fclose(fp);
    }

    printf("%d\n", ret);

    return ret == number;
}
