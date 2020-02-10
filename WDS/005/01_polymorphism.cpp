#include <iostream>

// 测试多态-虚函数

using namespace std;

class Base{
private:
    int not_use; //用于计算空间大小时占用空间使用
public:
    // 虚函数
    virtual void hello(void)
    {
        cout << "Base Hello " << endl;
    }
};

//公有继承Base
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
};

/*
    因为Base::hello 为虚函数，使用的是动态联编
    所有当不同类的对传入给print_hello()时，会去动态查找类的成员

    如果Base::hello 不是虚函数，那么print_hello()只会调用Base::hello，不会动态的去查找

    静态联编：非虚函数，在编译时就确定好调用关系
    动态联编：虚函数，在运行时才确定调用关系

    动态联编原理：
        1. 对象里面有指针，指向一个虚函数表
        2. 调用函数时，通过指针找到虚函数表中对应的函数
*/

// 这里必须是引用或指针
void print_hello(Base &base)
{
    base.hello();
}



int main(int argc, char *argv[])
{
    Base base;
    A a;
    B b;

    // 自动调用Base::hello
    print_hello(base);

    // 自动调用A::hello
    print_hello(a);

    // 自动调用b::hello
    print_hello(b);

    // 大小都为16，如果Base::hello不是虚函数，则大小都为4
    cout << "Base:" << sizeof(base) << endl;
    cout << "A:" << sizeof(a) << endl;
    cout << "B:" << sizeof(b) << endl;

    return 0;
}
