#include <iostream>

using namespace std;

int main(void)
{
    int *p = new int;
    *p = 20;

    cout << "p:" << *p << endl;

    delete p;

    return 0;
}
