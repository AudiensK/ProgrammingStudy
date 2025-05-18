// 结构中的结构
// struct dateANDtime {
//     struct date dates;
//     struct time times;
// };

#include <stdio.h>

struct point {
    int x, y;
};

struct rectangle {
    struct point start;
    struct point end;
};

struct rectangle set_rectangle(struct point start, int length, int width);
void print_rectangle(struct rectangle rectangles);


int main()
{
    int i;
    struct rectangle rects[3] = {
        {{0, 0}, {6, 6}},
        {{1, 2}, {-3, 5}},
    };

    rects[2] = set_rectangle((struct point){-1, -1}, 10, 20);

    for (i = 0; i < 3; i++) {
        printf("The %ds rectangle is from ", i + 1);
        print_rectangle(rects[i]);
    }

    // 如果有变量定义
    struct rectangle r, *rp;
    rp = &r;
    // 那么四种形式以下是等效的
    r.start.x;
    (r.start).x;  // 其实不需要括号，因为.的运算也是从左到右
    rp->start.x;
    (rp->start).x;
    // rp->start->x;  // 这种写法错误，因为start不是指针

    return 0;
}


struct rectangle set_rectangle(struct point start, int length, int width)
{
    struct point end;
    end.x = start.x + length;
    end.y = start.y + width;
    struct rectangle ret = {.start = start, .end = end};  // 不要忘记运算符.

    return ret;
}


void print_rectangle(struct rectangle rectangles)
{
    printf("(%d.%d) to (%d.%d).\n", 
        rectangles.start.x, rectangles.start.y, rectangles.end.x, rectangles.end.y);
}