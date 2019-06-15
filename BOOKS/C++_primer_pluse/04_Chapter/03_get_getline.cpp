#include <iostream>
#include <cstring>

int main(void)
{
    using namespace std;
    char name1[20] = {};
    char name2[20] = {};

    cout << "please input name1:";
    cin.get(name1, 20).get();//must use cin.get(xx).get()
    cout << "input name1 is:" << name1 << endl;
    cout << "input name1 len:" << strlen(name1) << endl;

    cout << "please input name2:";
    cin.getline(name2, 20);
    cout << "input name2 is:" << name2 << endl;
    cout << "input name2 len:" << strlen(name2) << endl;

    return 0;
}
