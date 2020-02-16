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
    // 这里必须使用虚函数，否则派类的析构只会调用~Human
    virtual ~Human();
};

Human &CreateEnglishman(char *name, int age, char *address);
Human &CreateChinese(char *name, int age, char *address);

#endif
