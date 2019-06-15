#include <iostream>

using namespace std;

int main(void)
{
    char ch; 
    int count = 0;

    cout << "Enter character; enter # to quit" << endl;

    cin >> ch;
    while ('#' != ch)
    {
        //无法识别空格
        cout << ch;
        count ++;
        cin >> ch;
    }

    cout << endl;
    cout << count << " characters read" << endl;

    return 0;
}
