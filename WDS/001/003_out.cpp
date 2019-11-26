#include <stdio.h>

// 将函数写到类的外面

class Person {
private:
    char *name;
    int age;
    char *work;

public:
    // 可以直接访问内部的成员
    void print_info(void);
    int set_name(char *name);
    int set_age(int age);
    int set_work(char *work);
};

void Person::print_info(void)
{
    printf("name:%s \n", name);
    printf("age:%d \n", age);
    printf("work:%s \n", work);
}

int Person::set_name(char *name)
{
    // 参数和成员名相同
    // 使用this-> 表示这是对象的成员
    this->name = name;

    return 0;
}

int Person::set_age(int age)
{
    if (age < 0 || age > 200)
    {
        this->age = 0;
    }
    else
    {
        this->age = age;
    }

    return this->age;
}

int Person::set_work(char *work)
{
    this->work = work;
    return 0;
}

int main(int argc, char *argv[])
{
    Person per;

    per.set_age(10);
    per.set_name("AAA");
    per.set_work("BBB");

    per.print_info();
    return 0;
}


