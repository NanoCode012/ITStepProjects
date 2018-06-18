#include <iostream>
#include "Flat.h"

using namespace std;

int main()
{
    Flat f(100, 20);
    f.Output();

    Flat f2(25, 59);
    f2.Output();

    cout << ((f == f2) ? "f and f2 have the same area" : "f and f2 does not have the same area") << endl;
    cout << ((f > f2) ? "f is more expensive than f2" : "f2 is more expensive than f") << endl;

    Flat f3;
    f3 = f;
    f3.Output();

    return 0;
}