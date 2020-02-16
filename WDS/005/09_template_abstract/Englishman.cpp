#include "Englishman.h"
#include <string.h>

void Englishman::eating(void)
{
    cout << "Englishman eating " << endl;
}

void Englishman::wearing(void)
{
    cout << "Englishman wearing " << endl;
}

void Englishman::driver(void)
{
    cout << "Englishman driver " << endl;
}

void Englishman::print_info(void)
{
    cout << "Name:" << GetName() <<  ",Age:" << this->age << ",Address:" << this->address << endl;
}

// 空的构造函数
Englishman::Englishman()
{
    //nothing
}

Englishman::~Englishman()
{
    cout << "~Englishman" << endl;
}

Englishman::Englishman(char *name, int age, char *address)
{
    SetName(name);
    this->age = age;
    memset(this->address, 0, 1000);
    strcpy(this->address, address);
}

Human &CreateEnglishman(char *name, int age, char *address)
{
    return *(new Englishman(name, age, address));
}