#include <stdio.h>
#include <string.h>

// 定义学生结构体
struct Student {
    char name[50];
    int age;
    float score;
};

int main() {
    // 声明一个学生结构体变量
    struct Student s1;
    // 声明一个学生结构体变量并初始化
    struct Student s2 = {.name = {"Jack"}, .age = 18};

    // 初始化结构体变量
    strcpy(s1.name, "John");
    s1.age = 20;
    s1.score = 85.5;

    // 打印学生信息
    printf("Name: %s\n", s1.name);
    printf("Age: %d\n", s1.age);
    printf("Score: %.2f\n", s1.score);

    printf("\n");
    printf("Name: %s\n", s2.name);
    printf("Age: %d\n", s2.age);
    printf("Score: %.2f\n", s2.score);

    return 0;
}