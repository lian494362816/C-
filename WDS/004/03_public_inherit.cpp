#include <iostream>

// 测试类的public继承，调整属性

using namespace std;

class A{
private:
    int A_pri_val;
protected:
    int A_pro_val;
public:
    int A_pub_val;

    void A_set_pri_val(int val)
    {
        this->A_pri_val = val;
    }

    int A_get_pri_val(void)
    {
        return this->A_pri_val;
    }

    void A_set_pro_val(int val)
    {
        this->A_pro_val = val;
    }

    int A_get_pro_val(void)
    {
        return this->A_pro_val;
    }

    void A_print_info(void)
    {
        cout << "A_pri_val:" << A_pri_val;
        cout << ",A_pro_val:" << A_pro_val;
        cout << ",A_pub_val:" << A_pub_val << endl;
    }
};

// B 继承A
class B:public A{

private:
    // 将protected调整为私有属性
    using A::A_pro_val;
protected:
    // 将publibc调整为protected属性
    using A::A_pub_val;
public:
    void B_set_pri_val(int val)
    {
        // 不能直接访问基类的私有成员
        A_set_pri_val(val);
    }

    void B_set_pro_val(int val)
    {
        // 可以直接访问基类的保护成员
        this->A_pro_val = val;
    }

    void B_set_pub_val(int val)
    {
        // 可以直接访问基类的公有成员
        this->A_pub_val = val;
    }
};

int main(int argc, char *argv[])
{
    A class_a;
    B class_b;

    class_a.A_set_pri_val(10);
    class_a.A_set_pro_val(30);
    class_a.A_pub_val = 20;
    class_a.A_print_info();

    //B可以调用A的所有public函数,变量
    class_b.B_set_pri_val(11);
    class_b.B_set_pro_val(22);
    // A_pub_val已经调整为protected属性，不能直接访问
    class_b.B_set_pub_val(33);
    class_b.A_print_info();

    return 0;
}
