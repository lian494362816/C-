#include <iostream>

int main(void)
{
    using namespace std;

    int year;
    char address[30] = {};

    cout << "when year is your house build:";
    (cin >> year).get();
    cout << "What is ist address:";
    cin.getline(address, 30);

    cout << "your house build in:" << year << endl;
    cout << "your house address is:" << address << endl;

    return 0;
}
