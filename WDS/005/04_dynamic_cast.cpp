#include <iostream>

// 测试动态转换dynamic_cast

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

// 使用dynamic_cast找到对象的类
// 当对象所属的类为A和B时,涉及了隐式的上行转换
void find_class(Base &base)
{
    Base *pbase;
    A    *pa;
    B    *pb;

/*
    // 都可以转换为pbase
    if (pbase = dynamic_cast<Base *>(&base))
    {
        cout << "Class Base " << endl;
    }
*/
    // 下行转换, 父类到子类
    if (pa = dynamic_cast<A *>(&base))
    {
        cout << "Class A" << endl;
    }

    // 下行转换， 父类到子类
    if (pb = dynamic_cast<B *>(&base))
    {
        cout << "Class B" << endl;
    }
}

/*
    原理：
    使用到虚函数时，虚函数表里面有类的信息
    可以从类的信息找到对象所属的类
*/

int main(int argc, char *argv[])
{
    Base base;
    A a;
    B b;

    find_class(base);
    find_class(a);
    find_class(b);

    return 0;
}
