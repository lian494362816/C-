#ifndef _DOG_H_
#define _DOG_H_

namespace DOG{
class Dog {
private:
    char *name;
    int age;

public:
    void print_info(void);
    int set_name(char *name);
    int set_age(int age);
};

void print_version(void);
}
#endif // _DOG_H_

