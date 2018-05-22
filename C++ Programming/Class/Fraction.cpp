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
}

void Fraction::Multiply(Fraction other)
{
    numerator *= other.numerator;
    denominator *= other.denominator;
}

void Fraction::Divide(Fraction other)
{
    numerator *= other.denominator;
    denominator *= other.numerator;
}

void Fraction::Show()
{
    cout << numerator << "/" << denominator << endl;
}