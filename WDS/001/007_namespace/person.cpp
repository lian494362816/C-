#include <stdio.h>
#include "person.h"

namespace PERSON{

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


void print_version(void)
{
    printf("Person, version \n");
}

}
