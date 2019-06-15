#include <iostream>

using namespace std;

int main(void)
{
    int i = 0;
    int *p = new int [5];

    for (i = 0; i < 5; i++)
    {
        p[i] = i+1; 
    }

    for (i = 0; i < 5; i++)
    {
        cout <<"p[" << i << "]=" << p[i] << endl;
    }

    delete [] p;

    return 0;
}
