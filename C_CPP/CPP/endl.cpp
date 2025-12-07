/*
"\n"：仅仅是一个字符串字面量，表示换行符（ASCII 码中的0x0A），作用是在输出流中插入一个换行。
    "\n"性能更好：仅插入换行符，不会触发缓冲区刷新，减少了 I/O 操作，适合大量输出的场景（如循环打印）。

endl：是 C++ 标准库中的一个操纵符（manipulator），它的功能有两个：
    在输出流中插入一个换行符（与"\n"的换行功能相同）
    强制刷新输出缓冲区（调用flush()操作）
    endl有性能开销：每次使用都会强制刷新缓冲区，而 I/O 操作相对耗时。
    在频繁输出的情况下（如日志循环），过度使用endl可能导致程序运行效率下降。

输出缓冲区（output buffer）是内存中用于临时存储待输出数据的临时区域。
    刷新缓冲区（flushing the buffer）指的是将缓冲区中的数据实际写入到目标设备（如控制台、文件等）的操作。
*/

#include <iostream>
#include <chrono>
#include <thread>

int main() {
    // 使用"\n"
    std::cout << "Hello1\n";  // 仅插入换行，不主动刷新缓冲区
    // Hello1会立即显示，这并不是因为 \n 自动刷新了缓冲区，而是因为标准输出到终端时通常采用行缓冲模式，\
    在非交互式环境（如重定向到文件）中，这种行为可能会不同。
    std::this_thread::sleep_for(std::chrono::seconds(5));  // 休眠5秒
 
    
    // 使用endl
    std::cout << "Hello2" << std::endl;  // 插入换行 + 刷新缓冲区
    
    return 0;
}