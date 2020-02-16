#include "Chinese.h"
#include "Englishman.h"

int main(int argc, char *argv[])
{
    Chinese c;
    Englishman e;

    c.SetName("Shenzhen");
    cout << "c:" << c.GetName() << endl;
    c.eating();
    c.wearing();
    c.driver();

    cout << "==========" << endl;

    e.SetName("Jhon");
    cout << "e:" << e.GetName() << endl;
    e.eating();
    e.wearing();
    e.driver();

    return 0;
}
