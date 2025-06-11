// 在文件中定位

/* long ftell(FILE *stream);
成功：返回当前位置的字节偏移量（类型为 long）。
失败：返回 -1L，并设置 errno。*/ 

/* int fseek(FILE *stream, long offset, int whence);
    offset：偏移量（字节数），可正可负。
    whence：起始位置，取值为以下宏定义：
        SEEK_SET（0）：从文件开头计算偏移。
        SEEK_CUR（1）：从当前位置计算偏移。
        SEEK_END（2）：从文件末尾计算偏移（此时 offset 通常为负数）。
    成功：返回 0。失败：返回非零值（通常为 -1），并设置 errno。*/

#include <stdio.h>
#include "student.h"

int read(const char* filename);
int printAll(const char* filename);


int main()
{
    char* filename = "student.data";
    int n;

QUERY:
    printf("1.查询所有学生信息\n2.按编号查询学生信息\n0.退出查询\n请输入选项号码：");
    scanf("%d", &n);

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        printAll(filename); 
    } else if (n == 2) {
        read(filename);
    } else {
        goto QUERY;
    } 

    return 0;
}

int read(const char* filename)
{
    int ret = -1;

    FILE *fp = fopen(filename, "r");

    if (fp) {
        fseek(fp, 0L, 2);
        long size = ftell(fp);
        int number = size / sizeof(Student);

        int index;
        printf("现有%d条学生信息，请输入需要查询的学生编号（1-%d）:\n", number, number);
        scanf("%d", &index);
        while (index <= 0 || index > number) {
            printf("该编号学生信息不存在，请重新输入：");
            scanf("%d", &index);
        }
        --index;       

        // 读取对应位置的学生信息，并保存与aStu中
        Student aStu;
        fseek(fp, index * sizeof(Student), SEEK_SET);  // 将读写位置移动至对应位置
        ret = fread(&aStu, sizeof(Student), 1, fp);  // 读取1个信息存入aStu
        fclose(fp);

        // 判断文件是否正确读取
        if (ret != 1) {
            printf("文件读取失败！仅读取了 %d 条记录，需要 %d 条记录。\n", ret, number);
            return ret;
        }

        // 打印信息
        const char *gender;  // 该指针将指向一个常量，因此需要const
        switch(aStu.gender) {
            case 0: gender = "男"; break;
            case 1: gender = "女"; break;
            case 2: gender = "其他"; break;
            default: gender = "ERROR"; break;
        }
        // 打印信息
        printf("第%d个学生：\n\t姓名：%s\n\t性别：%s\n\t年龄：%d 岁\n", index + 1, aStu.name, gender, aStu.age);
        
        return ret;
    } else {
        printf("文件打开失败！\n");
        return ret;
    }

}

int printAll(const char* filename)
{
    int ret = -1;

    // 打开文件
    FILE *fp = fopen(filename, "r");
    // FILE *fp = fopen(filename, "rb");  // rb二进制读取

    // 判断文件是否成功打开
    if (!fp) {
        printf("文件打开失败！\n");
        return ret;
    }

    // 计算文件中学生信息数量
    fseek(fp, 0L, SEEK_END);  // 移动读写位置到末尾，0L表示不偏移，L表示long
    long size = ftell(fp);  // 获得当前位置字节偏移量
    // 文件字节数除以Student结构的字节数得到文件中有多少个这样的结构
    int number = size / sizeof(Student);  

    // 创建结构数组暂存数据
    // 也可以直接用ftell,fseek移动读写位置来直接读取数据
    Student aStu[number];

    // 读取文件并存入相应的数据结构
    fseek(fp, 0L, SEEK_SET);  // 将读写位置移动到开头
    ret = fread(aStu, sizeof(Student), number, fp);
    // 关闭文件
    fclose(fp);
    // 判断文件是否正确读取
    if (ret != number) {
        printf("文件读取失败！仅读取了 %d 条记录，需要 %d 条记录。\n", ret, number);
        return ret;
    }

    // 遍历数组，输出结构中所有信息
    for (int i = 0; i < number; i++) {
        // 替换数字为性别
        const char *gender;
        switch(aStu[i].gender) {
            case 0: gender = "男"; break;
            case 1: gender = "女"; break;
            case 2: gender = "其他"; break;
            default: gender = "ERROR"; break;
        }
        // 打印信息
        printf("第%d个学生：\n\t姓名：%s\n\t性别：%s\n\t年龄：%d 岁\n", i + 1, aStu[i].name, gender, aStu[i].age);
    }

    return ret == number;
}

