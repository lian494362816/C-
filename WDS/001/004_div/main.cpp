#include <stdio.h>
#include "person.h"

// 把类的实现拆分成多个文件
// person.h 提供类的声明
// person.cpp 提供各种函数的实现

int main(int argc, char *argv[])
{
    Person per;

    per.set_age(10);
    per.set_name("AAA");
    per.set_work("BBB");

    per.print_info();
    return 0;
}

