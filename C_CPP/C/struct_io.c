// 没有直接的方式可以一次scanf一个结构
// 把一个结构变量作为参数传入函数，是在函数中生成了外面那个结构的克隆体，和数组不一样
// 可以在这个函数中创建一个临时结构变量，然后把这个结构返回给调用者，不过这种方法既费空间，又费时间
// 更好的办法是传入结构变量指针
/*
struct date {
    int month;
    int day;
    int year;
} today;

struct date* p = &today;  // 创建一个结构指针 指向 结构变量today

(*p).month = 12;  // 运算符.的优先级更高
p -> month = 12;  // 等同于上面一种写法，-> 用arrow符号表示指针所指向的结构中的成员

*/

#include <stdio.h>

//struct point getStruct(void);
struct point* getStruct(struct point* d);
void print(const struct point* p);
void outPut(struct point d);


struct point {
    int x;
    int y;
};


int main(int argc, char const *argv[])
{
    struct point y = {};
    // y = getStruct();
    // outPut(y);

    // 结构的地址等于结构中第一个成员的地址，结构中成员在内存中是依次排列的
    struct point x = {2, 3};
    struct point* p = &x;
    int *p1 = &x.x;
    int *p2 = &x.y;
    printf("\n*p=%p\np1=%p\np2=%p\n", p, p1, p2); 
    (*p).x = 12;
    printf("x.x=%d\n", x.x);
    p -> x = 11;
    printf("x.x=%d\n", x.x);
    *p1 = 10;
    printf("x.x=%d\n", x.x);
    //printf("*p.y=%d", *p.y);  // 报错，因为*p.y相当于*(p.y)
    printf("\n");

    outPut(y);
    getStruct(&y);
    outPut(y);
    //outPut(*getStruct(&y));
    //print(getStruct(&y));
    //getStruct(&y) ->x = 0;  // 给指针所指向的结构成员赋值
    //*getStruct(&y) = (struct point){3, 1};  // 结构直接赋值

    return 0;
}


// struct point getStruct(void)
// {
//     struct point d;
//     printf("Enter x y\n");
//     scanf("%d %d", &d.x, &d.y);

//     return d;
// }


struct point* getStruct(struct point* p)  // struct point*表示返回一个结构指针
{
    printf("Enter x y\n");
    //scanf("%d %d", &(*p).x, &(*p).y);
    scanf("%d %d", &p->x, &p->y);
    printf("%d %d\n", p->x, p->y);

    return p;
}


void print(const struct point *p)
{
    printf("x=%d,y=%d\n", p->x, p->y);
}


void outPut(struct point d)
{
    printf("x=%d,y=%d\n", d.x, d.y);
}