#include <iostream>

// 测试构造函数

using namespace std;

class Person{
private:
    int age;
    const char *name;
    const char *work;

public:
    //构造函数
    Person(int age, char *name, const char *work="None")
    {
        cout << "Call Person Constructor" << endl;
        this->age = age;
        this->name = name;
        this->work = work;
    }

    // 空的构造函数
    Person()
    {
        cout << "Call Empty Person Constructor" << endl;
    }

    int set_name(char *name)
    {
        this->name = name;
        return 0;
    }

    int set_age(int age)
    {
        if (age <0 || age > 200)
        {
            this->age = -1;
            return -1;
        }

        this->age = age;

        return 0;
    }

    int set_work(char *work)
    {
        this->work = work;
        return 0;
    }

    void print_info(void)
    {
        cout << "name:" << name;
        cout << ",age:" << age;
        cout << ",work:" << work << endl;
    }
};

int main(int argc, char *argv[])
{
    //调用构造函数
    Person p1(10, "P1", "P1_Work");
    // work没有赋值，使用默认的数值
    Person p2(11, "P2");

    // 调用空的构造函数
    Person p3;

    // 调用2次空的构造函数
    Person p4[2];

    // 指针类型，申请了一个空间，调用空的构造函数
    // 可以使用 new Person()
    Person *p5 = new Person;

    // 指针类型，申请了2个空间, 调用2次空的构造函数
    Person *p6 = new Person[2];

    p1.print_info();
    p2.print_info();

    p5->set_age(20);
    p5->set_name("P5");
    p5->set_work("P5_Wrok");
    p5->print_info();

    // 删除指针
    delete p5;
    delete []p6;

    return 0;
}
