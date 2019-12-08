#include <iostream>
#include <string.h>

// 测试静态成员

using namespace std;

class Person{
private:
    int age;
    char *name;
    char *work;
    // 静态成员，这里只是声明，没有分配空间
    // 这个成员属于这个类，而不是属于某个对象，被所有对象共享
    static int count;
public:

    // 静态成员函数，属于这个类，而不是属于某个对象，被所有对象共享
    static int get_count(void)
    {
        cout << "count:" << count << endl;
        return count;
    }

    Person()
    {
        cout << "Person emtpy Construcotr" << endl;
        this->age = -1;
        this->name = NULL;
        this->work = NULL;
        this->count ++;
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
        memcpy(this->work, p.work, strlen(p.name));
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

// 在这里定义初始化类Person中静态成员count的数值
// 这样才分配了空间
int Person::count = 0;

int main(int argc, char *argv[])
{
    // 静态成员函数属于类，因此可以通过类+作用域限定符来访问
    // 这个时候还没有定义对象
    Person::get_count();

    Person p1;
    Person p2;
    Person p3;

    // 也可以通过某个对象来访问
    p1.get_count();

    Person::get_count();
}
