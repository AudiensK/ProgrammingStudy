// 结构数组
// 声明一个结构，然后用这个结构作为数组中的单元
// struct array a[100];
// struct array a[] = {
//     {1,2,3,4}, {2,3,4,5}};

#include <stdio.h>


struct time {
    int hours;
    int minutes;
    int seconds;
};


struct time gain_ten_seconds(struct time t);


int main(void)
{
    struct time testTimes[5] ={
        {12, 30, 00}, {13, 59, 55}, {1, 00, 20}, {2, 10, 30}, //{3, 15, 50},
    };  // 初始化结构数组，未指定值的单元会自动初始化为0

    int i;

    for (i = 0; i < 5; i++) {
        printf("Time is %dh,%dm,%ds.\n", 
            testTimes[i].hours, testTimes[i].minutes, testTimes[i].seconds);

        testTimes[i] = gain_ten_seconds(testTimes[i]);

        printf("After ten seconds,time is %dh,%dm,%ds.\n", 
            testTimes[i].hours, testTimes[i].minutes, testTimes[i].seconds);
    }

    return 0;
}


struct time gain_ten_seconds(struct time t)
{
    t.seconds += 10;
    if (t.seconds> 59) {
        t.seconds -= 60;
        t.minutes++;
    }
    if (t.minutes > 59) {
        t.minutes -= 60;
        t.hours++;
    }

    return t;
}