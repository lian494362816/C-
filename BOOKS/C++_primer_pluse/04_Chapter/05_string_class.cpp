#include <iostream>
#include <string>

int main(void)
{
    using namespace std; 

    string str1 = "123"; 
    string str2 = "abc"; 
    string str3;

    cout << "str1:" << str1;
    cout << " len:" << str1.size() << endl;

    cout << "str2:" << str2;
    cout << " len:" << str2.size() << endl;

    str3 = str1 + str2;
    cout << "str3:" << str3;
    cout << " len:" << str3.size() << endl;

    return 0;
}
