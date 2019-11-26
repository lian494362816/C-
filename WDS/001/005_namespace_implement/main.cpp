#include <stdio.h>
#include "person.h"
#include "dog.h"
// class dog 和 person里面都有print_version函数
// 使用命令空间来区分


int main(int argc, char *argv[])
{
    // 这里必须指明命令空间
    DOG::Dog d;
    PERSON::Person p;

    d.set_name("little dog");
    d.set_age(2);

    p.set_name("man");
    p.set_age(20);
    p.set_work("student");

    d.print_info();
    p.print_info();

    // 这里使用命令空间来区分名字相同的函数
    DOG::print_version();
    PERSON::print_version();

    return 0;
}

