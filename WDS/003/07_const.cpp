#include <iostream>
#include <string.h>

// 测试const 对象

using namespace std;

class Person{
private:
    int age;
    char *name;
    char *work;

public:
    //构造函数
    Person(int age, char *name, const char *work="None")
    {
        cout << "Call Person Constructor" << endl;
        this->age = age;

        // 申请空间
        this->name = new char[strlen(name) + 1];
        memcpy(this->name, name, strlen(name));
        this->name[strlen(name)] = '\0';

        this->work = new char[strlen(work) + 1];
        memcpy(this->work, work, strlen(work));
        this->work[strlen(work)] = '\0';

    }

    // 空的构造函数
    Person()
    {
        cout << "Call Empty Person Constructor" << endl;
        this->age = -1;
        this->name = NULL;
        this->work = NULL;
    }

    // 拷贝构造函数, 这里必须添加const
    Person(const Person & p)
    {
        cout << "Call Person Copy Constructor " << endl;

        this->age = p.age;

        this->name = new char[strlen(p.name) + 1];
        memcpy(this->name, p.name, strlen(p.name));

        this->work = new char[strlen(p.work) + 1];
        memcpy(this->work, p.work, strlen(p.work));
    }

    // 析构函数
    ~Person()
    {
        cout << "Call Deconstructor" << endl;
        if (this->name)
            delete this->name;

        if (this->work)
            delete this->work;
    }

    // 这里添加const, 表示不会修改里面的任何数据
    void print_info(void) const
    {
        cout << "name:" << this->name;
        cout << ",age:" << this->age;
        cout << ",work:" << this->work << endl;
    }
};


int main(int argc, char *argv[])
{
    const Person p1(10, "P1", "P1_Work");

    // 会调用拷贝构造函数, 拷贝构造函数必须使用const修饰，否则编译报错
    Person p2 = p1;

    // print_info 后面必须使用const修饰
    // 因为const 对象只能调用const修饰的成员函数
    p1.print_info();

    p2.print_info();
    return 0;
}
