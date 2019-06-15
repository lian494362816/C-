#include <iostream>
using namespace std;

int main(void)
{
    char ch;
    int count = 0;

    cout << "Enter character; Enter # to quit" << endl;

    cin.get(ch);
    while('#' != ch)
    {
        cout << ch;
        count ++;
        cin.get(ch);
        //可以统计空格
    }
    cout << endl;
    cout << count << " characters read" << endl;
    
    return 0;
}
