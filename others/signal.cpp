#include <iostream>

// 进程类
class Process {
public: 
    char name;
    int pid;
};

// 记录型信号量数据结构
class Semaphore {
public:
    int value;
    int* procession;
};

// 进程调度程序（模拟按时间轮转）
void processes_rotate(const Process (&ready_procession)[4], int& pointer_of_read, int& time)
{
    // 获取就绪队列大小
    int size = sizeof(ready_procession) / sizeof(Process);
    
    // 测试程序
    // printf("就绪队列大小%d\n", size);
    // for (int i = 0; i < size; i++) 
    // {
    //     printf("%c\n", ready_procession[i].name);
    // }

    // 获取玩家输入用于模拟时间推进
    int get = 1;
    // 按就绪队列依次调度进程，如果为闲散进程（idle），则跳过当前调度下一个进程
    while (!ready_procession[pointer_of_read].pid) {
        pointer_of_read++;
        if (pointer_of_read >= size) pointer_of_read %= size;
    }
    std::cout << "当前时间片为：" << time << ",就绪队列指针为：" << pointer_of_read << std::endl;
    std::cout << "CPU正在运行进程" << ready_procession[pointer_of_read].name << std::endl;
    std::cout << "输入0结束程序，输入1推进时间" << std::endl;
    // 循环调度
    while (get) {
        std::cin >> get;
        if (get) 
        {
            do {
                pointer_of_read++;
                if (pointer_of_read >= size) pointer_of_read %= size;
            } while (!ready_procession[pointer_of_read].pid);
            
            time++;
            std::cout << "当前时间为：" << time << ",就绪队列指针为：" << pointer_of_read << std::endl;
            std::cout << "CPU正在运行进程" << ready_procession[pointer_of_read].name << std::endl;
            
        } else {
            std::cout << "结束程序。";
            break;
        }
    }
}

// 主模拟程序
int main()
{
    // 设置就绪队列和阻塞队列
    Process ready_procession[4] = {};
    int pointer_of_read = 0; // 就绪队列指针
    Process block_procession[4] = {};
    int pointer_of_block = 0;

    // 初始化4个进程
    Process a, b, c, d, idle;
    a.name = 'a'; b.name = 'b'; c.name = 'c'; d.name = 'd'; idle.name = 'i';
    a.pid = 1; b.pid = 2; c.pid = 3; d.pid = 4; idle.pid = 0;

    // 将进程加入就绪队列
    ready_procession[0] = a;
    ready_procession[1] = b;
    ready_procession[2] = c;
    ready_procession[3] = d;

    // 设置时间
    int time = 0;

    // 进程调度
    processes_rotate(ready_procession, pointer_of_read, time);

    return 0;
}