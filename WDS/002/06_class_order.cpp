#include <iostream>
#include <string.h>

// 测试构造函数的调用顺序

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
        cout <<"Person Deconstructor ";
        cout << "name:" << name;
        cout << ",age:" << age;
        cout << ",wrok:" << work << endl;
        if (this->name)
            delete this->name;

        if (this->work)
            delete this->work;
    }

};

// 全局的在main函数调用之前调用
static Person g_p(1, "g_p");

void func(void)
{
    // 静态的只调用一次
    static Person static_func_p(1, "static_func_p");

    // func调用几次，构造函数就调用几次
    Person func_p(1,"func_p");
}

int main(int argc, char *argv[])
{
    int i = 0;

    cout << "main start ===== " << endl;
    // 静态的只调用一次
    static Person static_main_p(1, "static_main_p");

    // 只运行1次，因此只调用1次构造函数
    Person func_p(1,"main_p");

    for (i = 0; i < 3; i++)
    {
        cout << "for_p, i:" << i;
        cout << "#########" << endl;

       // for调用几次，构造函数就调用几次，
        Person for_p(1, "for_p");
    }

    for (i = 0; i < 2; i++)
    {
        cout << "func, i:" << i;
        cout << "#########" << endl;
        func();
    }

    cout << "main end ====== " << endl;

    // 静态和全局的析构函数在最后调用
    // 调用的顺序跟构造函数的顺序相反
}
