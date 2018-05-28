#include "Fraction.h"

using namespace std;

void Fraction::SetInitialValue(int num, int denom)
{
    numerator = num;
    denominator = denom;
}

void Fraction::Add(Fraction other)
{
    if (denominator == other.denominator)
    {
        numerator += other.numerator;
    }
    else
    {
        numerator = (numerator * other.denominator) + (other.numerator * denominator);
        denominator *= other.denominator;
    }
    Simplify();
}

void Fraction::Subtract(Fraction other)
{
    if (denominator == other.denominator)
    {
        numerator -= other.numerator;
    }
    else
    {
        numerator = (numerator * other.denominator) - (other.numerator * denominator);
        denominator *= other.denominator;
    }
    Simplify();
}

void Fraction::Multiply(Fraction other)
{
    numerator *= other.numerator;
    denominator *= other.denominator;
    Simplify();
}

void Fraction::Divide(Fraction other)
{
    numerator *= other.denominator;
    denominator *= other.numerator;
    Simplify();
}

void Fraction::Show()
{
    cout << numerator << "/" << denominator << endl;
}

void Fraction::Simplify()
{
    int greatestCommonDivisor = GCD(numerator, denominator);
    if (greatestCommonDivisor > 0)
    {
        numerator /= greatestCommonDivisor;
        denominator /= greatestCommonDivisor;
    }
}

int GCD(int a, int b)
{
    if (b <= 0)
    {
        return a;
    }
    else return GCD(b, a - (b * (a / b)));
}