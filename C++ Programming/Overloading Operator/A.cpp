#include "A.h"

using namespace std;

A::A(int n)
{
    this->a = n;
}

A A::operator+(const A &other)
{
    return A(this->a + other.a);
}
A A::operator-(const A &other)
{
    return A(this->a - other.a);
}
A A::operator*(const A &other)
{
    return A(this->a * other.a);
}
A A::operator/(const A &other)
{
    return A(this->a / other.a);
}

void A::Output()
{
    cout << this->a << endl;
}