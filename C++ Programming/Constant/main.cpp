#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
    Person p;
    p.SetAge(5);
    cout << p.GetAge() << endl;
    return 0;
}