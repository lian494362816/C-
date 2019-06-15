#include <iostream>
#include <climits>

int main(void)
{
    using namespace std;
    short short_max = SHRT_MAX;
    int int_max = INT_MAX;
    long long_max = LONG_MAX;
    long long long_long_max = LLONG_MAX;

    cout << "short is " << sizeof(short) << " bytes" << endl;
    cout << "int is " << sizeof(int) << " bytes." << endl;
    cout << "long is " << sizeof(long) << " bytes." << endl;
    cout << "long long is " << sizeof(long long) << " bytes." << endl;

    cout << "short max:" << short_max << endl;
    cout << "int max:" << int_max << endl;
    cout << "long max:" << long_max << endl;
    cout << "long long max:" << long_long_max << endl;
         

    return 0;
}
