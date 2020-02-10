#include <iostream>

// 测试多态-析构虚函数

using namespace std;

class Base{
public:
    // 虚函数
    virtual void hello(void)
    {
        cout << "Base Hello " << endl;
    }

    // 虚函数
    virtual ~Base()
    {
        cout <<"~Base()" << endl;
    }
};

//公有继承Base
class A:public Base{
public:
    void hello(void)
    {
        cout << "A Hello" << endl;
    }

     // 虚函数
    virtual ~A()
    {
        cout << "~A()" << endl;
    }
};

//公有继承Base
class B:public Base{
public:
    void hello(void)
    {
        cout << "B Hello" << endl;
    }

     // 虚函数
    virtual ~B()
    {
        cout << "~B()" << endl;
    }
};

int main(int argc, char *argv[])
{
    Base *p = NULL;
    Base *pbase = new Base;
    A *pa = new A;
    B *pb = new B;

    // 自动调用Base::hello
    p = pbase;
    p->hello();

    // 自动调用A::hello
    p = pa;
    p->hello();

    // 自动调用B::hello
    p = pb;
    p->hello();

    cout << "=======" << endl;


    //如果析构函数不是虚函数, 则只会调用到~Base()

    // 调用~Base
    p = pbase;
    delete p;

    // 先调用~A, 再调用~Base,
    p = pa;
    delete p;

    // 先调用~B, 再调用~Base,
    p = pb;
    delete p;

    return 0;
}
