#include <iostream>
#include <string>
using namespace std;

// 基类 (父类)
class Animal {
public:
    Animal(string name) : name(name) { // 基类构造函数
        cout << "Animal constructor called for " << name << endl;
    }
    virtual ~Animal() { // 🔥 基类析构函数最好声明为 virtual (尤其在有继承时)
        cout << "Animal destructor called for " << name << endl;
    }
    virtual void makeSound() const { // 🔥 虚函数，允许派生类重写以实现多态
        cout << name << " makes a generic animal sound." << endl;
    }
    void eat() const { // 非虚函数
        cout << name << " is eating." << endl;
    }
protected:
    string getName() const { // protected 成员，派生类可直接访问
        return name;
    }
private:
    string name; // private 成员，派生类不可直接访问
};

// 派生类 (子类) - public 继承
class Dog : public Animal {
public:
    Dog(string name, string breed) : Animal(name), breed(breed) { // 调用基类构造函数初始化基类部分
        cout << "Dog constructor called for " << getName() << " (" << breed << ")" << endl;
    }
    ~Dog() override { // 重写基类虚析构函数，override 关键字确保正确重写
        cout << "Dog destructor called for " << getName() << endl;
    }
    void makeSound() const override { // 🔥 重写基类虚函数，实现 Dog 特有的行为
        cout << getName() << " (" << breed << ") says Woof!" << endl;
    }
    void fetch() const { // 派生类新增的成员函数
        cout << getName() << " is fetching the ball!" << endl;
    }
private:
    string breed; // 派生类新增的私有数据成员
};

int main() {
    // 1. 创建派生类对象
    Dog myDog("Buddy", "Golden Retriever");

    // 2. 调用继承自基类的函数
    myDog.eat(); // 输出: Buddy is eating.

    // 3. 调用重写的虚函数 (多态)
    myDog.makeSound(); // 输出: Buddy (Golden Retriever) says Woof!

    // 4. 调用派生类新增的函数
    myDog.fetch(); // 输出: Buddy is fetching the ball!

    cout << "\nDemonstrating polymorphism with base pointer:\n";
    // 5. 🔥 多态: 基类指针指向派生类对象
    Animal* animalPtr = &myDog;
    animalPtr->makeSound(); // 输出: Buddy (Golden Retriever) says Woof!
                            // 调用的是 Dog::makeSound(), 因为 makeSound 是虚函数

    // animalPtr->fetch(); // 错误！基类指针看不到派生类特有的成员

    return 0;
    // main 结束时，myDog 析构:
    //   Dog destructor called for Buddy
    //   Animal destructor called for Buddy
}