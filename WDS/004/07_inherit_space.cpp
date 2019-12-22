#include <iostream>

// 测试派生类的内存分布

using namespace std;

class A{
private:
    int A_pri;
public:

    void A_set_pri(int val)
    {
        A_pri = val;
    }

    void print_info(void)
    {
        cout << "A_print_info" << endl;
        cout << "A_pri:" << this->A_pri << endl;
    }
};

// 公有继承
class B:public A{
private:
    int B_pri;
public:

    void B_set_pri(int val)
    {
        B_pri = val;
    }

    void print_info(void)
    {
        A::print_info();
        cout << "B_print_info" << endl;
        cout << "B_pri:" << this->B_pri << endl;
    }
};

void print_info(A &p)
{
    p.print_info();
}

int main(int argc, char *argv[])
{
    A class_a;
    B class_b;

    class_a.A_set_pri(10);

    class_b.A_set_pri(20);
    class_b.B_set_pri(30);

    //调用A的print_info
    class_a.print_info();
    cout << "=======" << endl;
    //调用B的print_info
    class_b.print_info();
    cout << "=======" << endl;

    // 调用A的print_info
    print_info(class_a);
    cout << "=======" << endl;

    // 调用A的print_info
    print_info(class_b);

    return 0;
}
