#include <iostream>

int main(void)
{
    using namespace std;

    int yams[3];
    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 9;
    
    int yamcost[3] = {21, 24, 27};

    cout << "yams[0] = " << yams[0] << endl;
    cout << "yams[1] = " << yams[1] << endl;
    cout << "yams[2] = " << yams[2] << endl;
    cout << endl;

    cout << "yamcost[0] = " << yamcost[0] << endl;
    cout << "yamsost[1] = " << yamcost[1] << endl;
    cout << "yamsost[2] = " << yamcost[2] << endl;
    cout << endl;

    cout << "yams[0] * yamcost[0] = " << yams[0] * yamcost[0] << endl;
    cout << "yams[1] * yamcost[1] = " << yams[1] * yamcost[1] << endl;
    cout << "yams[2] * yamcost[2] = " << yams[2] * yamcost[2] << endl;
    cout << endl;

    cout << "sizeof yams[0] = " << sizeof yams[0] << endl;
    cout << "sizeof yams = " << sizeof yams << endl;

    cout << "sizeof yamcost[0] = " << sizeof yamcost[0] << endl;
    cout << "sizeof yamcost = " << sizeof yamcost << endl;

    return 0;
}
