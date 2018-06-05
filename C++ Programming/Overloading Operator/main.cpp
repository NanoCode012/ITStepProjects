#include <iostream>
#include "A.h"

using namespace std;

int main()
{
    A a1(2);
    A a2(2);
    A a3 = a1 + a2;
    a3.Output();
    return 0;
}