#include "acllib.h"
#include <stdio.h>

void mouseListener(int x, int y, int button, int event);
void keyListener(int key, int event);
void timerListener(int id);


int Setup()
{
    char title[100] = "ACLLibPractice";
    // 坐标系是以像素点的数字来定义的。\
    对于你创建的窗口，左上角是(0,0)，x轴自左向右增长，而y轴自上向下增长
    int left = DEFAULT, top = DEFAULT;
    int width = 1080, height = 720;

    // 初始化窗口
    initWindow(title, left, top, width, height);
    // 初始化终端窗口
    // initConsole();

    printf("Hello!\n");
    int px = 100, py = 100;
    

    // 在窗口中绘制
    beginPaint();  // 开始绘制
    setPenColor(BLUE);  // 设置画笔颜色
    setPenWidth(1);  // 设置画笔宽度
    setPenStyle(PEN_STYLE_DASHDOTDOT); // 设置画笔样式
    line(100, 100, 500, 500);  // 画线
    // scanf("%d %d", &px, &py);  // 用户输入数据前，绘制窗口未响应，不会开始任何绘制直到用户输入
    lineTo(px, py);
    // setPenWidth(10);  // 对putPixel没有作用
    putPixel(200, 100, RGB(255, 0, 255));
    putPixel(150, 100, GREEN);
    // 绘制贝塞尔曲线
    setPenWidth(3);
    setPenColor(RGB(125, 125, 125)); 

    POINT p[] = 
    {
        {0, 0},  // 起点
        {150, 0},  // 起点控制点
        {0, 150},  // 第二点的第一个控制点
        {200, 300},  // 第二点
        {500, 500},  // 第二点的第二个控制点
        // 以此类推...
        {700, 600},  // 终点控制点
        {1080, 720},  // 终点
    };

    polyBezier(p, 7);  // 绘制贝塞尔曲线  // p为节点，7为节点数量

    endPaint();  // 结束绘制


    // 注册回调函数
    // 注册函数和调用函数分开，register仅用于注册回调函数，\
    当符合条件时另一个函数（比如MouseEvent）会调用这个回调函数
    registerMouseEvent(mouseListener);  
    registerKeyboardEvent(keyListener);
    registerTimerEvent(timerListener);

    // 定时器
    startTimer(0, 500);  // 定时器编号0，每500毫秒调用一次回调函数
    startTimer(1, 1000);

    return 0;
}


void mouseListener(int x, int y, int button, int event)  // 作为回调函数必须符合其对应的函数指针（返回类型、传入参数等要保持一致）
{
    static int ox = 0, oy = 0;
    // printf("x=%d, y=%d, button=%d, event=%d\n", x, y, button, event);
    if (button == LEFT_BUTTON && event == BUTTON_DOWN) {
        ox = x; oy = y;
    } else if (button == LEFT_BUTTON && event == BUTTON_UP) {
        beginPaint();
        line(ox, oy, x, y);
        endPaint();
    }
}

void keyListener(int key, int event)
{
    printf("key=%d, event=%d\n", key, event);
}

void timerListener(int id)
{
    static int cnt = 0;
    if (id == 0) {
        if (cnt++ >= 5) {
            cancelTimer(id);
        }    
    }      

    printf("id=%d,cnt=%d\n", id, cnt);

}

// 编译命令：gcc main.c acllib.c -o main.exe -lgdi32 -lole32 -loleaut32 -luuid -lwinmm -lmsimg32