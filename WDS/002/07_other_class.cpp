#include <iostream>
#include <string.h>

// 测试对象中有其它类

using namespace std;

class Person{
private:
    int age;
    char *name;
    char *work;

public:

    Person()
    {
        cout << "Person emtpy Construcotr" << endl;
        this->age = -1;
        this->name = NULL;
        this->work = NULL;
    }

    //构造函数
    Person(int age, char *name, const char *work="None")
    {
        cout <<"Person Constructor ";
        cout << "name:" << name;
        cout << ",age:" << age;
        cout << ",wrok:" << work << endl;
        this->age = age;

        // 申请空间
        this->name = new char[strlen(name) + 1];
        memcpy(this->name, name, strlen(name));
        this->name[strlen(name)] = '\0';

        this->work = new char[strlen(work) + 1];
        memcpy(this->work, work, strlen(work));
        this->work[strlen(work)] = '\0';

    }

    // 拷贝构造函数
    Person(const Person & p)
    {
        // cout << "Call Person Copy Constructor " << endl;

        this->age = p.age;

        this->name = new char[strlen(p.name) + 1];
        memcpy(this->name, p.name, strlen(p.name));

        this->work = new char[strlen(p.work) + 1];
        memcpy(this->work, p.work, strlen(p.work));
    }

    // 析构函数
    ~Person()
    {
        cout <<"Person Deconstructor " << endl;

        if (this->name)
        {
            cout << "name:" << name;
            delete this->name;
        }

        if (this->age != -1)
            cout << ",age:" << age;

        if (this->work)
        {
            cout << ",wrok:" << work << endl;
            delete this->work;
        }
    }

};

class Student {
private:
    // 成员里面有其它的类，先调用这个类的够函数
    Person father;
    Person mother;
    int age;
public:

    // 后调用自己的构造函数
    // 空的构造函数
    Student()
    {
        cout << "Student empty Constructor" << endl;
    }

    // 通过:将参数传给其它类的构造函数
    Student(int father_age, char *father_name, char *father_work,
               int mother_age, char *mother_name, char *mother_work,
               int stu_age):father(father_age, father_name, father_work),mother(mother_age, mother_name, mother_work)
    {
        cout <<"Student Constructor" << endl;
    }

    // 析构函数
    ~Student(void)
    {
        cout << "Student Deconstructor " << endl;
    }
};

/*
 *  会先调用对象中其它类的构造函数
 *  再调用自己的构造函数
 *  析构函数的调用顺序与构造函数的调用顺序相反
*/

int main(int argc, char *argv[])
{
    Student stu1;

    // 可以把参数传给对象中其它类的构造函数
    Student stu2(40, "f", "f_work", 42, "m", "m_work", 8);
}
