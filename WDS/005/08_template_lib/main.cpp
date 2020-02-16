#include "Chinese.h"
#include "Englishman.h"
#include "Human.h"

void print_info(Human *h)
{
    cout << "name:" << h->GetName() << endl;
    h->eating();
    h->wearing();
    h->driver();
}

int main(int argc, char *argv[])
{
    Chinese c;
    Englishman e;
    Human *h[2] = {&c, &e};
    int i = 0;

    c.SetName("LCC");
    e.SetName("Black");

    for (i = 0; i < 2; i++)
    {
        print_info(h[i]);
    }

    return 0;
}
