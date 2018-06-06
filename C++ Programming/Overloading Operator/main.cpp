#include <iostream>
#include "A.h"
#include "SomeClass.h"

using namespace std;

int main()
{
    A a1(2);
    A a2(2);
    A a3 = a1 + a2;
    a3.Output();

    SomeClass *someClass = new SomeClass;
    SomeClass *someClass2 = new SomeClass[3];
    delete someClass;
    delete[] someClass2;
    return 0;
}