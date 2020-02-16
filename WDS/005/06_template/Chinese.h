#ifndef _CHINESE_H_
#define _CHINESE_H_

#include <iostream>
#include "Human.h"

using namespace std;

class Chinese:public Human{
public:
    //三个成员, 吃、穿、开车
    void eating(void);
    void wearing(void);
    void driver(void);
};

#endif
