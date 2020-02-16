#ifndef _CHINESE_H_
#define _CHINESE_H_

#include <iostream>
#include "Human.h"

using namespace std;

class Chinese:public Human{
private:
    int age;
    char address[100];
public:
    //三个成员, 吃、穿、开车
    void eating(void);
    void wearing(void);
    void driver(void);
    void print_info(void);
    Chinese();
    Chinese(int age, char *name, char *string);
    ~Chinese();
};

#endif
