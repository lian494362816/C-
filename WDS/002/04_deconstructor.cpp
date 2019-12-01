#include <iostream>
#include <string.h>

// 测试构造函数-析构函数

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

    void print_info(void)
    {
        cout << "name:" << name;
        cout << ",age:" << age;
        cout << ",work:" << work << endl;
    }
};

void func_test1(void)
{
    // 初始化时，会调用构造函数，里面会调用new申请空间
    Person p1(10, "P1", "P1_Work");

    p1.print_info();

    // 函数退出时，会调用析构函数，删除申请的空间
}

void func_test2(void)
{
    Person *p2 = new Person;

    // 初始化时，会调用构造函数，里面会调用new申请空间
    p2->set_age(20);
    p2->set_name("P2");
    p2->set_work("P2_Work");

    // 需要手动调用delete才会触发析构函数
    delete p2;
}

int main(int argc, char *argv[])
{
    int i = 0;

    cout << "######func_test1#########" << endl;
    while(i < 5)
    {
        cout << "i:" << i << "=================" << endl;
        func_test1();
        i++;
    }

    i = 0;
    cout << "######func_test2#########" << endl;
    while(i < 5)
    {
        cout << "i:" << i << "=================" << endl;
        func_test2();
        i++;
    }


    return 0;
}
