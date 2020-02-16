#ifndef _HUMAN_H_
#define _HUMAN_H_

#include <iostream>

class Human{
private:
    char *name;
public:
    void SetName(char *name);
    char * GetName(void);

    virtual void eating(void) = 0;
    virtual void wearing(void) = 0;
    virtual void driver(void) = 0;

    Human();
    ~Human();
};

#endif
