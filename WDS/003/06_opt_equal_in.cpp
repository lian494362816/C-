#include <iostream>
#include <string.h>

// 测试拷贝构造函数和重载运算符等号的调用区别

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

    // 拷贝构造函数
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

    int set_name(char *name)
    {
        //调用的是空的构造函数，没有申请过内存 或 长度不够
        if (!this->name || strlen(this->name) - 1 < strlen(name))
        {
            // 释放后重新申请
            if (this->name)
            {
                delete this->name;
            }
            this->name = new char[strlen(name) + 1];
            memcpy(this->name, name, strlen(name));
            this->name[strlen(name)] = '\0';
        }
        else
        {
            memcpy(this->name, name, strlen(name));
            this->name[strlen(name)] = '\0';
        }

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
        //调用的是空的构造函数，没有申请过内存 或 长度不够
        if (!this->work || strlen(this->work) - 1 < strlen(work))
        {
            // 释放后重新申请
            if (this->work)
            {
                delete this->work;
            }
            this->work = new char[strlen(work) + 1];
            memcpy(this->work, work, strlen(work));
            this->work[strlen(work)] = '\0';
        }
        else
        {
            memcpy(this->work, work, strlen(work));
            this->work[strlen(work)] = '\0';
        }

        return 0;
    }

    //重载等号运算符
    Person &operator=(Person &p)
    {
        cout <<"Call operator=" << endl;
        this->age = p.age;

        // 如果名字和工作都存在，需要先释放
        if (this->name)
        {
            delete this->name;
        }

        if (this->work)
        {
            delete this->work;
        }
        this->name = new char[strlen(p.name) + 1];
        memcpy(this->name, p.name, strlen(p.name));

        this->work = new char[strlen(p.work) + 1];
        memcpy(this->work, p.work, strlen(p.work));

        return *this;
    }

    void print_info(void)
    {
        cout << "name:" << name;
        cout << ",age:" << age;
        cout << ",work:" << work << endl;
    }
};


/*
    在创建对象并使用=赋值时, 调用拷贝构造函数
    在创建完对象之后使用=赋值时, 调用重载运算符=
*/

int main(int argc, char *argv[])
{
    Person p1(10, "P1", "P1_Work");

    // 会调用拷贝构造函数
    Person p2 = p1;

    Person p3;

    // 会调用=操作符, 因为先调用了空的构造函数，后面不能再次调用拷贝构造函数了
    p3 = p1;

    p1.print_info();
    p2.print_info();
    p3.print_info();

    return 0;
}
