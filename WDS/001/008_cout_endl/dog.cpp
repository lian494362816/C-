#include <stdio.h>
#include <iostream>
#include "dog.h"

// 将函数写到类的外面
namespace DOG{

void Dog::print_info(void)
{
    std::cout << "name:"  << name << std::endl;
    std::cout << "aeg:" << age << std::endl;
}

int Dog::set_name(char *name)
{
    // 参数和成员名相同
    // 使用this-> 表示这是对象的成员
    this->name = name;

    return 0;
}

int Dog::set_age(int age)
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

void print_version(void)
{
    std::cout << "Dog, version " << std::endl;
}

}
