#include <stdio.h>

// 定义颜色枚举类型
// enum Color {
//     RED = 101,
//     GREEN = 102,
//     BLUE = 103,
//     YELLOW = 104
// };

// 使用typedef定义枚举类型
typedef enum {
    RED = 101,
    GREEN = 102,
    BLUE = 103,
    YELLOW = 104
} Color;


// 函数：根据枚举值打印颜色信息
// void printColorInfo(enum Color color) {
void printColorInfo(Color color) {  // 可省略enum关键词
    printf("颜色代码: %d, ", color);
    
    switch(color) {
        case RED:
            printf("名称: 红色\n");
            break;
        case GREEN:
            printf("名称: 绿色\n");
            break;
        case BLUE:
            printf("名称: 蓝色\n");
            break;
        case YELLOW:
            printf("名称: 黄色\n");
            break;
        default:
            printf("未知颜色\n");
    }
}

int main() {
    // 声明枚举变量并初始化
    // enum Color favoriteColor = BLUE;
    Color favoriteColor = BLUE;
    
    // 打印默认颜色
    printf("我最喜欢的颜色是: ");
    printColorInfo(favoriteColor);
    
    // 修改颜色值
    favoriteColor = YELLOW;
    printf("我现在最喜欢的颜色是: ");
    printColorInfo(favoriteColor);
    
    // 使用整数值赋值（需谨慎）
    // favoriteColor = (enum Color)101; // 等价于 RED
    favoriteColor = (Color)101;
    printf("通过整数值设置的颜色是: ");
    printColorInfo(favoriteColor);
    
    return 0;
}