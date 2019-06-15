#include <iostream>
#include <cstring>

int main(void)
{
    using namespace std; 

    char name1[32] = "C++ Word";
    char name2[32] = {};

    cout << "my name is:" << name1 << endl;
    cout << "please input your name:";
    cin >> name2;
    cout << "hello " << name2 << endl;
    cout << "your name is " << strlen(name2) << " letters" << endl;

    return 0;
}

