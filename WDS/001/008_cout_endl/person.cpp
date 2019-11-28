#include <stdio.h>
#include <iostream>
#include "person.h"

namespace PERSON{

void Person::print_info(void)
{
    std::cout << "name:" << name << std::endl;
    std::cout << "age:" << age << std::endl;
    std::cout << "work" << work << std::endl;
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


void print_version(void)
{
    std::cout << "Person, version " << std::endl;
}

}
