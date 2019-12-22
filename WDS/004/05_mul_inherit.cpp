#include <iostream>

// 测试类的多重继承属性

using namespace std;

class A{
private:
    int A_pri_val;
protected:
    int A_pro_val;
public:
    int A_pub_val;

    void A_pub_print_test(void)
    {
        cout << "print test " << endl;
    }

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
        cout << "A_print_info" << endl;
        cout << "A_pri_val:" << A_pri_val;
        cout << ",A_pro_val:" << A_pro_val;
        cout << ",A_pub_val:" << A_pub_val << endl;
    }
};


// 公有继承
class pub_B:public A{
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


// 保护继承
class pro_B:protected A{
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

    void B_print_info(void)
    {
        cout << "B_print_info" << endl;
        cout << "A_pri_val:" << A_get_pri_val();
        cout << ",A_pro_val:" << A_pro_val;
        cout << ",A_pub_val:" << A_pub_val << endl;
    }
};


// 私有继承
class pri_B:private A{
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

    void B_print_info(void)
    {
        cout << "B_print_info" << endl;
        cout << "A_pri_val:" << A_get_pri_val();
        cout << ",A_pro_val:" << A_pro_val;
        cout << ",A_pub_val:" << A_pub_val << endl;
    }

};


// 继承公有派生类B
// 基类A的属性全部不变
class C_pub : public pub_B{
public:
    void C_set_pri_val(int val)
    {
        // 不可以直接访问公有派生类B的私有成员
        B_set_pri_val(val);
    }

    void C_set_pro_val(int val)
    {
        // 可以直接访问公有派生类B的保护成员
        this->A_pro_val = val;
    }

    void C_set_pub_val(int val)
    {
        // 可以直接访问公有派生类B的公共成员
        this->A_pub_val = val;
    }
};


// 继承保护派生类B
// 基类A的pub属性变为pro
class C_pro : public pro_B{
public:

    void C_set_pri_val(int val)
    {
        // 不可以直接访问保护派生类B的私有成员
        B_set_pri_val(val);
    }

    void C_set_pro_val(int val)
    {
        // 可以直接访问保护派生类B的保护成员
        this->A_pro_val = val;
    }

    void C_set_pub_val(int val)
    {
        // pub_B是保护继承于A，因此pub成员属性变为了pro
        // 可以直接访问保护派生类B的保护成员
        this->A_pub_val = val;
    }
};


// 继承私有派生类B
// 基类A的所有属性变为pri
class C_pri : public pri_B{
public:
    void C_set_pri_val(int val)
    {
        // 不可以直接访问私有派生类B的私有成员
        B_set_pri_val(val);
    }

    void C_set_pro_val(int val)
    {
        // pub_B是保护继承于A，因此pro成员属性变为了pri
        // 不可以直接访问私有派生类B的私有成员
        B_set_pro_val(val);
    }

    void C_set_pub_val(int val)
    {
        // pub_B是保护继承于A，因此pub成员属性变为了pri
        // 不可以直接访问私有派生类B的私有成员
        B_set_pub_val(val);
    }

};

int main(int argc, char *argv[])
{
    C_pub class_c_pub;
    C_pro class_c_pro;
    C_pri class_c_pri;

    //pub_b公共继承于A,因此C_pub还可以访问到A的pub成员
    class_c_pub.A_set_pri_val(10);
    class_c_pub.A_set_pro_val(20);
    class_c_pub.A_pub_val = 30;
    class_c_pub.A_print_info();

    //pro_b保护继承于A,A的pub成员已经变为pro,因此C_pro无法访问A的pub成员
    class_c_pro.B_set_pri_val(11);
    class_c_pro.B_set_pro_val(21);
    class_c_pro.B_set_pub_val(31);
    class_c_pro.B_print_info();

    //pri_b私有继承于A,A的所有成员已经变为pri,因此C_pro无法访问A的任何成员
    class_c_pri.B_set_pri_val(12);
    class_c_pri.B_set_pro_val(22);
    class_c_pri.B_set_pub_val(32);
    class_c_pri.B_print_info();
    return 0;
}
