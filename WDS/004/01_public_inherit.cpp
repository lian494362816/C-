#include <iostream>

// 测试类的public 继承

using namespace std;

class A{
private:
    int A_pri_val;
public:
    int A_pub_val;

#if 0 //构造函数继承会报错，先屏蔽掉
    A(int pri_val, int pub_val)
    {
        this->A_pri_val = pri_val;
        this->A_pub_val = pub_val;
    }
#endif

    void A_set_pri_val(int val)
    {
        this->A_pri_val = val;
    }

    void A_set_pub_val(int val)
    {
        this->A_pub_val = val;
    }

    void A_print_info(void)
    {
        cout << "A_pri_val:" << A_pri_val;
        cout << ",A_pub_val:" << A_pub_val << endl;
    }
};

// B 继承A
class B:public A{
};

int main(int argc, char *argv[])
{
    A class_a;
    B class_b;

    class_a.A_set_pri_val(10);
    class_a.A_set_pub_val(20);
    class_a.A_print_info();

    //B可以调用A的所有pub函数,变量
    class_b.A_set_pri_val(20);
    class_b.A_set_pub_val(30);
    class_b.A_print_info();

    return 0;
}
