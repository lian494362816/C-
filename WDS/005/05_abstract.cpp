#include <iostream>

// 测试抽象类

using namespace std;

// 有纯虚函数成员的类为抽象类
class Base{

public:
    // 纯虚函数
    virtual void hello(void) = 0;
    virtual void print(void) = 0;
};

//公有继承Base, 没有复写print,因此class A还是一个抽象类
class A:public Base{
public:
    void hello(void)
    {
        cout << "A Hello" << endl;
    }
};

class B:public Base{
public:
    void hello(void)
    {
        cout << "B Hello" << endl;
    }

    void print()
    {
        cout << "B print" << endl;
    }
};


int main(int argc, char *argv[])
{
    //抽象类不能实例对象
    //Base base;
    //A a;

    B b;

    return 0;
}
