#include <iostream>

using namespace std;

const int SIZE = 5;

void display(const string *p, int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        cout << "[" << i + 1 << "]:" << p[i] << endl;
    }
}

int main(void)
{
    string list[SIZE];
    int i = 0;

    cout << "Enter your " << SIZE << " favorite food " << endl;

    for (i = 0; i < SIZE; i++)
    {
        cout << i + 1 << ":";
        cin >> list[i];
        // cin.getline(list[i]);
    }

    cout << "Your favorite food list:" << endl;

    display(list, SIZE);

    return 0;
}
