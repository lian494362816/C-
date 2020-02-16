#include "Human.h"
#include <string.h>

void Human::SetName(char *name)
{
    int len;

    len = strlen(name);

    if (!this->name || (strlen(this->name) <= len))
    {
        if (this->name)
        {
            delete this->name;
        }
        // 申请空间
        this->name = new char[len + 1];
    }

    memcpy(this->name, name, len);
    // 设置结尾
    this->name[len] = '\0';
}

char *Human::GetName(void)
{
    return this->name;
}

Human::Human()
{
    this->name = NULL;
}

Human::~Human()
{
    if (this->name)
    {
        delete this->name;
        this->name = NULL;
    }
}