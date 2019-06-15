#include <iostream>

using namespace std;

int main(void)
{
    int array[10] = {0};
    int i = 0;

    for (i = 0; i < 10; i++)
    {
        array[i] = i + 1;
    }

    for (i = 0; i < 10; i++)
    {
        cout << "array[" << i << "]:" << array[i] << endl;
    }

    for (int &x: array)
    {
        x*= 10; 
    }

    for (i = 0; i < 10; i++)
    {
        cout << "array[" << i << "]:" << array[i] << endl;
    }


    for (int x : {1, 2, 3, 4})
    {
        cout << "x[" << x << "]:" << x <<  endl;
    }

    return 0;
}
