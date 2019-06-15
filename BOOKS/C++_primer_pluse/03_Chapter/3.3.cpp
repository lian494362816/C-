#include <iostream>

int main(void)
{
    using namespace std;
    char c = 'M';
    int i = c;

    cout << "char "  << c << " is: " << i << endl;
    c = c + 1;
    i = c;
    cout << "char + 1 = "  << c << " is: " << i << endl;

    cout << "please intput a char: ";
    cin >> c;
    cout << "your input char is:";
    cout.put(c);
    cout << endl;

    return 0;
}
