#ifndef _HUMAN_H_
#define _HUMAN_H_

#include <iostream>

class Human{
private:
    char *name;
public:
    void SetName(char *name);
    char * GetName(void);
    Human();
    ~Human();
};

#endif
