#include <iostream>
#include <cmath>

int main(void)
{
    using namespace std;

    double num;
    double result;


    cout << "Input a double num:" ;
    cin >> num;

    result = sqrt(num);
    cout << "sqrt(" << num << ")=" << result << endl;

}
