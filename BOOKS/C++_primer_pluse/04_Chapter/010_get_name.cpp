#include <iostream>
#include <cstring>

using namespace std;

char *get_name(void)
{
    char tmp[80] = {0};

    cout << "Input put a string:";
    cin >> tmp;
    
    char *p = new char[strlen(tmp) + 1];
    strcpy(p, tmp);

    return p;
}

int main(void)
{
    char *name;

    name = get_name();
    cout << "name:" << name << endl;
    delete [] name;

    name = get_name();
    cout << "name:" << name << endl;
    delete [] name;

    return 0;

}
