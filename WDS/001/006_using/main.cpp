#include <stdio.h>
#include "person.h"
#include "dog.h"
// class dog 和 person里面都有print_version函数
// 使用命令空间来区分


int main(int argc, char *argv[])
{
    // 这里使用了using
    using DOG::Dog;
    using PERSON::Person;

    // 因为上面使用了using, 所以这里不需要指定命名空间
    Dog d;
    Person p;

    d.set_name("little dog");
    d.set_age(2);

    p.set_name("man");
    p.set_age(20);
    p.set_work("student");

    d.print_info();
    p.print_info();

    // 这里使用了using, 因此下面的print_vsersion()
    // 就是指的DOG::print_version
    using DOG::print_version;
    print_version();

    // 这里必须使用命令空间来区分
    PERSON::print_version();

    return 0;
}

