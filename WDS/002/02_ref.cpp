#include <iostream>

// 测试引用

using namespace std;

// 引入就跟使用了一个别名一样
int add(int &a)
{
    a+=1;
    return a;
}

int main(int argc, char *argv[])
{
    int a = 99;
    int &b = a;

    cout << "a:" << a << endl;
    add(a);
    cout << "a:" << a << endl;

    b += 10;
    cout << "b:" << b << endl;
    cout << "a:" << a << endl;
        
    return 0;
}
