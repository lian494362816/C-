#include <stdio.h>
#include "person.h"
#include "dog.h"
// class dog 和 person里面都有print_version函数
// 使用命令空间来区分

// 这里使用了namspace
using namespace DOG;
using namespace PERSON;

int main(int argc, char *argv[])
{
    // 因为上面使用了namesapce, 所以这里不需要指定命名空间
    Dog d;
    Person p;

    d.set_name("little dog");
    d.set_age(2);

    p.set_name("man");
    p.set_age(20);
    p.set_work("student");

    d.print_info();
    p.print_info();

    // 上面使用了namesapce, 所以    这里必须使用命令空间来区分
    DOG::print_version();
    PERSON::print_version();

    return 0;
}

