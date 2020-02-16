#ifndef _ENGLISHMAN_H_
#define _ENGLISHMAN_H_

#include <iostream>
#include "Human.h"

using namespace std;

class Englishman:public Human{
public:
    //三个成员, 吃、穿、开车
    void eating(void);
    void wearing(void);
    void driver(void);
};

#endif

