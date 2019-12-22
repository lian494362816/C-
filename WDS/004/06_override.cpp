#include <iostream>

// 测试类的重写(override)

using namespace std;

class A{
public:
    void print_info(void)
    {
        cout << "A_print_info" << endl;
    }
};

// 公有继承
class B:public A{
public:
    // 函数成员名字与class A中的一样
    // 执行时会调用class B自己的成员
    void print_info(void)
    {
        cout << "B_print_info" << endl;
    }
};

int main(int argc, char *argv[])
{
    A a;
    B b;

    a.print_info();
    b.print_info();

    return 0;
}
