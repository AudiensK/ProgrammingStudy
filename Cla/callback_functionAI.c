// 在 C 语言中，回调函数（Callback Function） 是一种通过函数指针传递给其他函数的函数，\
其目的是在特定事件发生或某个条件满足时被调用。回调函数是实现事件驱动编程、异步操作和代码复用的重要机制。

/* 回调函数的核心是函数指针：
    函数指针：指向函数的指针变量，存储函数的入口地址。
    注册回调：将函数指针作为参数传递给另一个函数（称为调用者）。
    回调执行：调用者在合适的时机通过函数指针调用回调函数。*/


/* 回调函数允许代码具有更高的灵活性和可扩展性，常见场景包括：
    事件处理：当用户点击按钮、网络数据到达时触发回调。
    异步操作：任务完成后通过回调通知调用者。
    通用算法：将特定操作封装在回调中，使算法更通用（如排序中的比较函数）。*/



// 以下是一个完整的 C 语言回调函数示例，展示了如何使用回调函数实现一个简单的事件处理系统。\
这个示例包含了定时器、事件注册和回调执行的基本框架。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// 定义回调函数类型  
// 定义一个回调函数的类型以便于在定义需要传入该类型的函数作为参数的函数时不需要在括号内写这么一大串
typedef void (*EventHandler)(int event_id, void* data, size_t data_size);

// 事件结构体
typedef struct {
    int event_id;           // 事件ID
    EventHandler handler;   // 回调函数
    void* user_data;        // 用户数据
    size_t data_size;       // 数据大小
} Event;

// 事件管理器结构体
typedef struct {
    Event* events;          // 事件数组
    int capacity;           // 容量
    int count;              // 当前事件数量
} EventManager;

// 初始化事件管理器
EventManager* init_event_manager(int initial_capacity) {  // 传入容量，返回一个事件管理器结构
    EventManager* manager = (EventManager*)malloc(sizeof(EventManager));  // 为结构体分配空间
    if (!manager) return NULL;  // 分配内存失败返回NULL
    
    // 初始化事件管理结构
    manager->capacity = initial_capacity;
    manager->count = 0;
    manager->events = (Event*)malloc(sizeof(Event) * initial_capacity);  // 为事件结构体分配空间
    if (!manager->events) {  // 如果分配内存失败
        free(manager);  // 释放事件管理器结构的内存
        return NULL;  // 返回NULL
    }
    
    return manager;  // 返回事件管理器结构
}

// 注册事件回调
// 传入事件管理器结构体，事件ID，回调函数，用户数据，数据大小，返回void
void register_event(EventManager* manager, int event_id, EventHandler handler, 
                   void* user_data, size_t data_size) {
    if (!manager || !handler) return;  // 如果事件管理器或回调函数为NULL，则直接return结束函数
    
    // 检查是否需要扩容
    if (manager->count >= manager->capacity) {
        manager->capacity *= 2;
        manager->events = (Event*)realloc(manager->events, 
                                           sizeof(Event) * manager->capacity);
    }
    
    // 注册事件
    Event* event = &manager->events[manager->count++];
    event->event_id = event_id;
    event->handler = handler;
    event->user_data = user_data;
    event->data_size = data_size;
}

// 触发事件
void trigger_event(EventManager* manager, int event_id, void* data, size_t data_size) {
    if (!manager) return;
    
    for (int i = 0; i < manager->count; i++) {
        if (manager->events[i].event_id == event_id) {
            // 调用回调函数
            manager->events[i].handler(event_id, data, data_size);
        }
    }
}

// 清理事件管理器
void destroy_event_manager(EventManager* manager) {
    if (!manager) return;
    free(manager->events);
    free(manager);
}

// 示例回调函数：打印事件信息
void print_event_handler(int event_id, void* data, size_t data_size) {
    printf("Event %d triggered with data: ", event_id);
    if (data && data_size > 0) {
        printf("%.*s\n", (int)data_size, (char*)data);
    } else {
        printf("(no data)\n");
    }
}

// 示例回调函数：计算数据长度
void calculate_length_handler(int event_id, void* data, size_t data_size) {
    if (data && data_size > 0) {
        printf("Event %d: Data length = %zu bytes\n", event_id, data_size);
    } else {
        printf("Event %d: No data provided\n", event_id);
    }
}

// 模拟定时器事件
void timer_event(EventManager* manager, int interval_ms) {
    static int timer_id = 1000;
    static clock_t last_time = 0;
    
    clock_t current_time = clock();
    if ((current_time - last_time) * 1000 / CLOCKS_PER_SEC >= interval_ms) {
        last_time = current_time;
        printf("Timer tick (ID=%d)\n", timer_id);
        trigger_event(manager, timer_id, NULL, 0);
    }
}

int main() {
    // 初始化事件管理器
    EventManager* manager = init_event_manager(5);
    if (!manager) {
        printf("Failed to initialize event manager\n");
        return 1;
    }
    
    // 注册事件回调
    register_event(manager, 1, print_event_handler, NULL, 0);
    register_event(manager, 2, calculate_length_handler, NULL, 0);
    
    // 准备数据
    char* message = "Hello, callback!";
    size_t message_len = strlen(message);
    
    // 触发事件
    printf("Triggering event 1...\n");
    trigger_event(manager, 1, message, message_len);
    
    printf("\nTriggering event 2...\n");
    trigger_event(manager, 2, message, message_len);
    
    printf("\nRegistering timer event...\n");
    register_event(manager, 1000, print_event_handler, NULL, 0);
    
    // 模拟主循环
    printf("\nRunning main loop (5 iterations)...\n");
    for (int i = 0; i < 5; i++) {
        timer_event(manager, 1000);  // 模拟1秒定时器
        // 主循环其他操作...
        printf("Main loop iteration %d\n", i + 1);
        Sleep(1000);  // 暂停1秒
    }
    
    // 清理资源
    destroy_event_manager(manager);
    return 0;
}