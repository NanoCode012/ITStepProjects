#include "Fraction.h"
#include <iostream>

using namespace std;

int main()
{
    Fraction f(1, 2);
    Fraction f2(3, 5);
    Fraction f3 = (f * f2);
    f3.Show(); cout << endl;
    f3 = (f / f2); 
    f3.Show(); cout << endl;
    return 0;
}