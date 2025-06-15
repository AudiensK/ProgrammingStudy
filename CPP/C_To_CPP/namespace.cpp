// 在 C++ 里，命名空间是一项极为重要的特性，\
它能够对全局作用域进行划分，从而避免不同代码实体（像类、函数、变量等）的命名出现冲突。

#include <iostream>

// 借助using声明和指令，能够简化对命名空间中实体的访问。
// 引入整个命名空间，不建议在头文件中使用,也不能在函数内部使用
// using namespace std;

// 只引入特定的实体
using std::cout, std::endl, std::cin;

namespace MyVariables
{
    // 命名空间内的变量和全局变量一样，都存储在静态存储区，\
    程序一旦启动，它们就会被创建，直到程序结束才会被销毁。
    // 命名空间变量默认具有外部链接属性（extern），这意味着它们在不同的编译单元中是可见的。
    int value = 42;

    void print() {
        cout << "MyVariables" << endl;
    }  // 函数体是执行语句的集合，用 {} 包裹。当右花括号 } 出现时，函数体逻辑已结束，无需额外分号：

    class MyClass {
        void print() {
            cout << "MyClass" << endl;
        }
    };

    // 命名空间可以进行嵌套，以此构建出层次化的结构。
    namespace MyVarInner
    {
        int value = 42;

        void print() {
            cout << "MyVarInner" << endl;
        }
    }

}  // 命名空间同样是作用域的划分，而非类型定义。右花括号 } 标志命名空间内容的结束，无需分号：

namespace MyFunctions
{
    void print() {
        cout << "MyFunctions" << endl;
    }
}

// 当命名空间的名称较长或者嵌套层次较深时，可以为其定义别名，使代码更加简洁。
namespace Mv = MyVariables;
namespace Mf = MyFunctions;

// 可以分开写，用别名写，都是同一个命名空间
namespace MyFunctions  // 不能用别名，会被当成新的命名空间
{
    struct point {
        int x;
        int y;
    };  // 结构体和类在 C++ 中是类型定义（Type Definition），\
    分号用于标记类型定义的结束。这允许在同一语句中声明该类型的变量
}

int main(void)
{
    // 若要访问命名空间中的实体，可使用作用域解析运算符::。
    cout << MyVariables::value << endl;

    // 当不同的库或者代码模块采用了相同的名称时，命名空间能够有效解决由此引发的冲突。
    Mv::print();
    Mf::print();

    // 访问嵌套命名空间中的实体
    Mv::MyVarInner::print();
    
    return 0;
}