#include <iostream>
#include <string.h>

// 测试拷贝构造函数

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

    void print_info(void)
    {
        cout << "name:" << name;
        cout << ",age:" << age;
        cout << ",work:" << work << endl;
    }
};


/*
 * 如果不提供拷贝构造函数，系统会调用默认的拷贝构造函数
 * 默认的拷贝构造函数，使用相同的地址
 * 当调用2次析构时，2次析构函数释放的是相同的指针
 * 导致指针被释放2次，因此需要自己实现拷贝构造函数
*/

int main(int argc, char *argv[])
{
    Person p1(10, "P1", "P1_Work");

    // 会调用拷贝构造函数
    Person p2 = p1;

    p1.print_info();
    p2.print_info();

    return 0;
}
