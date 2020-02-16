#include "Chinese.h"
#include <string.h>

void Chinese::eating(void)
{
    cout << "Chinese eating" << endl;
}

void Chinese::wearing(void)
{
    cout << "Chinese wraring " << endl;
}

void Chinese::driver(void)
{
    cout << "Chinese driver " << endl;
}

void Chinese::print_info(void)
{
    cout << "Name:" << GetName() <<  ",Age:" << this->age << ",Address:" << this->address << endl;
}

Chinese::Chinese()
{
    //nothing
}

Chinese::Chinese(int age, char *name, char *address)
{
    SetName(name);
    this->age = age;
    memset(this->address, 0, 100);
    strcpy(this->address, address);
}

Chinese::~Chinese()
{
    cout << "~Chinese" << endl;
}


Human &CreateChinese(char *name, int age, char *address)
{
    return *(new Chinese(age, name, address));
}
