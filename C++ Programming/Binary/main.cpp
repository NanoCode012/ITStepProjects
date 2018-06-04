#include <iostream>
#include "Binary.h"

using namespace std;

int main()
{
    Binary b(10);
    Binary b1(2);

    Binary b2 = b + b1;
    b2.Print();
    return 0;
}