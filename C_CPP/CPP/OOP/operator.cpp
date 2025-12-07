// 运算符重载（Operator Overloading）是 C++ 的核心特性之一，\
它允许我们为自定义类型（类或结构体）重新定义运算符的行为，\
使其能够像内置类型（如 int、float）一样进行直观的运算。\
语法： 返回类型 operator运算符(参数列表) { // 函数体 }

/*
可重载的运算符:
算术运算符	+, -, *, /, %, ++, --
关系运算符	==, !=, <, >, <=, >=
逻辑运算符	&&, ||, !
位运算符	&, |, ^, ~, <<, >>`
赋值运算符	=, +=, -=, *=, /=, %=
其他	[], (), ->, ,, new, delete

不可重载的运算符：::, .*, ., ?:, sizeof
*/

// 重载不能改变运算符的优先级和结合性，运算符重载函数不能有默认参数。

// 运算符函数既可以作为类的成员函数，也可以作为非成员函数（通常是友元函数）来实现。
// 返回新对象 vs 返回引用：算术运算返回新对象，赋值运算返回引用。

/*
在决定将运算符函数实现为成员函数还是非成员函数时，可参考以下准则：
赋值运算符（=）、下标运算符（[]）、函数调用运算符（()）以及成员访问运算符（->）必须被重载为成员函数。
具有对称性的运算符，例如算术运算符（+、-）和关系运算符（==、<），建议重载为非成员函数，这样能更好地支持混合类型的运算。
其他运算符既可以重载为成员函数，也可以重载为非成员函数。*/

/*
注意事项
语法限制：运算符的优先级、结合性和操作数数量都不能通过重载改变。
避免滥用：重载运算符时，要保证其行为符合该运算符的原始语义，例如重载+时，应确保它执行的是类似加法的操作。
特殊运算符：有些运算符，如&&、||，不建议重载，因为重载后会丧失短路求值的特性。
构造函数的作用：可以利用构造函数实现隐式类型转换，从而增强运算符重载的灵活性。
*/

#include <iostream>
#include <istream>
#include <ostream>

class ComplexNum
{
public:
    ComplexNum(double _real = 0, double _imaginary = 0) : real(_real), imaginary(_imaginary) {}
    ~ComplexNum() {}

    void logComplexNum()
    {
        std::cout << "(" << real << " + " << imaginary << "i)" << std::endl;
    }

    void operator++() // 重载一元运算符，有一个隐藏参数（this）
    // 如果做完运算后不需要直接利用，可以不返回
    {
        this->real++;
        this->imaginary++;
    }

    ComplexNum& operator-()
    // 返回自身的引用，不能返回void，因为做完=运算后可能会被用于其他地方
    {
        real = -real;
        imaginary = -imaginary;
        return *this; // this为对象的指针，返回对象的引用需要指针解引
    }
    
    ComplexNum operator+(const ComplexNum& other) const // 重载二元运算符，有两个参数，包含一个隐藏的this
    // 返回一个新的对象，每次调用运算符时，都会在栈上创建一个新的 ComplexNum 对象（即返回值）
    // 返回时可能需要调用拷贝构造函数，但是返回的是独立对象，调用者可以安全使用，不会因原对象生命周期结束而悬空。
    // 如果返回的是对象的引用，而以下函数体不变，ComplexNum& operator+(const ComplexNum& other)\
    由于函数内部创建的对象生命周期结束，返回值无法绑定到已销毁的对象上，即悬空引用，编译器会报错
    {
        return ComplexNum(real + other.real, imaginary + other.imaginary);

        // 如果返回的临时对象申请了内存，返回对象的引用，就不需要拷贝，但是有严重内存泄漏的风险
        // return *(new ComplexNum(real + other.real, imaginary + other.imaginary)); // 危险！
        // 使用 new 在堆上创建 ComplexNum 对象，但没有对应的 delete 操作。\
        如果返回的是引用，调用者无法通过引用得知对象需要手动释放，导致内存泄漏。
    }

    ComplexNum& operator=(const ComplexNum& other); // 重载赋值运算符
    // 赋值运算也有一个默认隐藏的函数，会实现浅拷贝。\
    若类不需要深拷贝，直接用默认的 operator= 即可（不用手动实现）。\
    若需要深拷贝，手动重载时必须复制所有成员变量，并正确管理动态资源。

    // 通过友元函数实现运算符重载
    friend ComplexNum operator-(const ComplexNum& other, const ComplexNum& another);

    /* 重载输入<<（流插入运算符）与输出>>（流提取运算符）
    1.必须作为非成员函数实现
    因为<<和>>的左操作数分别是ostream和istream对象（如cout、cin），而不是自定义类，
    因此只能通过友元函数或普通函数实现。
    2.参数和返回值
        第一个参数：ostream&类型的引用（通常为os）或istream&类型的引用（通常为is），用于接收实际的输出输入流对象。
        第二个参数：const YourClass&类型的引用
            （输出>>要避免拷贝，使用const保证安全性，而输入<<需要修改对象，不能用const）
        返回值：ostream&类型的引用，用于支持链式调用（如cout << a << b）。
            istream&类型的引用，用于支持链式调用（如cin >> a >> b）
    3.友元函数的使用
    如果需要访问类的私有成员，可将运算符函数声明为友元：*/
    friend std::istream& operator>>(std::istream& in, ComplexNum& cnum);
    friend std::ostream& operator<<(std::ostream& out, ComplexNum& cnum);
    
private:
    double real, imaginary;
};

// 运算符重载函数可以是非成员函数，由于要访问类的私有成员，通常是友元函数
ComplexNum operator-(const ComplexNum& other, const ComplexNum& another)
{
    return ComplexNum(other.real - another.real, other.imaginary - another.imaginary);
}

ComplexNum& ComplexNum::operator=(const ComplexNum& other) // 类内声明类外实现
{
    if (this != &other) {  // 防止自赋值
        real = other.real;
        imaginary = other.imaginary;
    }
    return *this;
}

// 重载输入输出
std::istream& operator>>(std::istream& is, ComplexNum& cnum)
{
    is >> cnum.real >> cnum.imaginary;
    // 错误处理：输入失败时需设置流的错误状态（如is.setstate(ios::failbit)）。
    if (is.fail()) {
        // 输入失败时的处理
        cnum = ComplexNum();  // 重置为默认值
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, ComplexNum& cnum)
{
    if (cnum.imaginary >= 0)
        os << "(" << cnum.real << " + " << cnum.imaginary << "i)";
    else
        os << "(" << cnum.real << " - " << -cnum.imaginary << "i)";
    return os;
}

int main()
{
    ComplexNum cnum1(3.1, 4.0);
    cnum1.logComplexNum();

    ComplexNum cnum2(4, 6.6);
    cnum2.logComplexNum();

    // 重载后的+号相当于一个函数，以下写法相当于cnum1.operator+(cnum2)
    ComplexNum cnum3 = cnum1 + cnum2;
    cnum3.logComplexNum();

    cnum3 = cnum1.operator+(cnum2);
    cnum3.logComplexNum();

    cnum3 = cnum1 + cnum2 + cnum3;
    cnum3.logComplexNum();
    // 重载=的类的对象使用=时会优先调用重载的=号。\
    

    ++cnum3;
    // cnum3++; // 重载一元运算符只能在左边（单目运算符）
    // cnum3 = ++cnum1; // 错误，因为operator++没有返回
    cnum3.logComplexNum();

    cnum3 = cnum1;
    cnum3.logComplexNum();

    cnum3 = -cnum1;
    cnum3.logComplexNum();

    cnum3 = cnum1 - cnum2;
    cnum3.logComplexNum();

    // 调用重载后的输入输出运算符
    ComplexNum cnum4;
    std::cout << "Enter two numbers to form a Complex:" << std::endl;
    // std::cin >> cnum4.real >> cnum4.imaginary; // 不重载的写法
    std::cin >> cnum4;
    // operator>>(std::cin, cnum4); // 以上等同于
    // std::cout << "(" << cnum4.real << " + " << cnum4.imaginary << "i)" << std::endl; // 不重载的写法
    std::cout << cnum4 << std::endl;
    // operator<<(std::cout, cnum4); // 以上等同于

    // 重载后的输入输出也可以连续使用
    std::cout << cnum1 << cnum2 << std::endl << cnum3 << cnum4 << std::endl;

    return 0;
}