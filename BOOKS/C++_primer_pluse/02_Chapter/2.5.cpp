#include <iostream>

void print_num(int num);


int main(void)
{
    using namespace std;
    int num;
    cout << "Default num" << endl;
    print_num(3);

    cout << "Please input int num:";
    cin >> num;
    print_num(num);
        
    return 0;
}

void print_num(int num) 
{
    using namespace std;

    cout << "Your input num is:" << num << endl;
}

