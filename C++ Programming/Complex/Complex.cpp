#include "Complex.h"

using namespace std;

Complex::Complex(int a, int b)
{
    this->a = Fraction(a);
    this->b = Fraction(b);
}

Complex::Complex(Fraction a, Fraction b)
{
    this->a = a;
    this->b = b;
}

Complex Complex::operator + (const Complex &other)
{
    Fraction a = this->a + other.a;
    Fraction b = this->b + other.b;
    return Complex(a, b);
}

Complex Complex::operator - (const Complex &other)
{
    Fraction a = this->a - other.a;
    Fraction b = this->b - other.b;
    return Complex(a, b);
}

Complex Complex::operator * (const Complex &other)
{
    Fraction a = (this->a * other.a) - (this->b * other.b);
    Fraction b = (this->a * other.b) + (this->b * other.a);
    return Complex(a, b);
}

Complex Complex::operator / (const Complex &other)
{
    Complex c = Complex(this->a, this->b) * Complex(other.a, Fraction(-1) * other.b);
    
	Fraction a = (other.a); a = a * (other.a);
	Fraction b = (other.b); b = b * (other.b);

    Fraction temp =  a + b;
    c.a = c.a / temp;
    c.b = c.b / temp;

    return c;
}

void Complex::Output()
{
    if (b.Compare(0) == 1)
    {
		cout << "(";
        a.Show();
        cout << ") + (";
        b.Show();
        cout << ")i";
    }
    else if (b.Compare(0) == -1)
    {
        b = b * Fraction(-1);

		cout << "(";
        a.Show();
        cout << ") - (";
		b.Show();
        cout << ")i";
    }
}