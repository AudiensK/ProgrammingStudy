#include <stdio.h>
#include <stdbool.h>


// 和本地变量一样，在函数内部声明的结构类型只能在该函数内部使用，所以通常在外部声明结构类型
struct date {  // 声明一个结构类型
    int month;  // 大括号内声明结构成员，成员类型 成员名字
    int day;
    int year;  // 最后一个元素也要有分号
};  // 注意别忘了这个分号

// // 声明结构的形式
// struct point{
//     int x;
//     int y;
// };
// struct point p1, p2;  // p1,p2都是point结构的变量，里面有x,y的值；

// struct {  // 这种写法没有声明point结构，无法在后续继续使用该结构声明变量，不常见。
//     int x;
//     int y;
// } p1, p2;  // p1,p2是该无名结构的变量，里面有x,y的值；

// struct point {
//     int x;
//     int y;
// } p1, p2;  // p1,p2都是point结构的变量，里面有x,y的值t；

/* 结构运算：
要访问整个变量，直接用结构变量的名字
对于整个结构，可以做赋值、取地址，也可以传递给函数参数
    p1 = (struct point){5， 10};  // (struct point)强制类型转换；相当于p1.x = 5;p1.y = 10;
    p1 = p2;  // 直接赋值；相当于p1.x = p2.x;p1.y = p2.y;
    以上两种都是数组不能做到的
*/

/* 结构指针
和数组不同，结构变量的名字并不是结构变量的地址，必须用&运算符取址
struct date *pDate = &today;  
*/

// 结构可以作为参数的值传入函数
// 这时候是在函数内新建一个结构变量，并复制调用者的结构的值
// 也可以返回一个结构
bool isLeap(struct date y);
struct date tomorrow(struct date d);


int main()
{
    struct date goneday;  // 声明一个date结构类型的变量today
    struct date today = {5, 16 ,2025};  // 声明一个date结构类型的变量today，并初始化；
    struct date todayzero = {.month = 5, .year = 2025};  // 声明一个date结构类型的变量todayzero，并初始化，其中未赋值的day会自动初始化为0；

    goneday.month = 12;  // 结构变量名.成员名 来访问结构成员； 点.也是一种运算符号
    goneday.day = 25;
    goneday.year = 1996;

    today = goneday;  // 可以直接赋值
    today.day = 31;

    struct date *pDate = &today;  // 指向结构变量的指针

    printf("%d年%d月%d日\n", goneday.year, goneday.month, goneday.day);
    printf("%d年%d月%d日\n", today.year, today.month, today.day);
    printf("%d年%d月%d日\n", todayzero.year, todayzero.month, todayzero.day);
    printf("pDate=%p\n", pDate);
    printf("\n");

    struct date d;
    printf("Enter today's date:(mm dd yy)\n");
    scanf("%d %d %d", &d.month, &d.day, &d.year);  // 可以看出运算符.优先级更高
    struct date t = tomorrow(d);
    printf("Tomorrow is %d-%d-%d\n", t.month, t.day, t.year);

    return 0;
}


struct date tomorrow(struct date d)
{
    int lastdayofamonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeap(d)) {
        lastdayofamonth[1] = 29;
    }

    if (d.day == lastdayofamonth[d.month - 1]) {
        d.day = 1;
        d.month++;
    } else {
        d.day++;
    }

    if (d.month > 12) {
        d.month = 1;
        d.year++;
    }

    return d;
}


bool isLeap(struct date y)
{
    bool leapyear = false;
    if ( (y.year % 100 != 0 && y.year % 4 == 0) || y.year % 400 == 0) {
        leapyear = true;
    }

    return leapyear;
}