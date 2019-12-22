#include <iostream>

// 测试类的publibc,protected,private继承的属性

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
};

// 私有继承
class pri_B:private A{
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

/*
           属性     属性     属性
           pub    pro    pri
继承方式
pub:       pub    pro    pri
pro:       pro    pro    pri
pri:       pri    pri    pri

    继承属性总结：
    1. 3种继承,pri 属性依旧保持不变
    2. pub继承，所有属性不变
    3. pro继承，pub属性变为pro
    4. pri继承，所有属性变为pri

    访问属性:
    1. 3种继承，在成员内部访问情况是一样的，可以访问pub和pro,不能访问pri
    2. pub继承，对象只能访问基类的pub成员
    3. pro继承，对象不能访问基类的任何成员
    4. pri继承，对象不能访问基类的任何成员
*/

int main(int argc, char *argv[])
{
    A class_a;
    pub_B class_pub_b;
    pro_B class_pro_b;
    pri_B class_pri_b;

    //  公有继承,所有属性不变,pub可以直接访问
    class_pub_b.A_pub_print_test();

    // 保护继承，pub属性变为pro,pro不可访问
    //class_pro_b.A_pub_print_test();

    // 私有继承，所有属性变为pri, pri不可访问
    //class_pri_b.A_pub_print_test();

    return 0;
}
