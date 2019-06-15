#include <iostream>

using namespace std;

int main(void)
{
    int a = 10;
    int *p = &a;

    cout << "value:" << a << " addr:" << &a << endl;
    cout << "p_valu:" << *p << " p_addr:" << p << endl;

    return 0;
}
