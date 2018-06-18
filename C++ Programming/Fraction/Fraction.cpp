#include "Fraction.h"

using namespace std;

Fraction::Fraction(int num, int denom)
{
    SetInitialValue(num, denom);
}

Fraction::Fraction(const Fraction &other) : Fraction(other.numerator, other.denominator)
{
}

void Fraction::operator = (const Fraction &other)
{
    SetInitialValue(other.numerator, other.denominator);
}

Fraction Fraction::operator + (const Fraction &other)
{
    return (Add(other));
}

Fraction Fraction::operator - (const Fraction &other)
{
    return (Subtract(other));
}

Fraction Fraction::operator * (const Fraction &other)
{
    return (Multiply(other));
}

Fraction Fraction::operator / (const Fraction &other)
{
    return (Divide(other));
}

void Fraction::SetInitialValue(int num, int denom)
{
    numerator = num;
    denominator = denom;
}

Fraction Fraction::Add(Fraction other)
{
    int tempNum = numerator;
    int tempDenom = denominator;
    if (denominator == other.denominator)
    {
        tempNum += other.numerator;
    }
    else
    {
        tempNum = (numerator * other.denominator) + (other.numerator * denominator);
        tempDenom *= other.denominator;
    }
    return Simplify(tempNum, tempDenom);
}

Fraction Fraction::Subtract(Fraction other)
{
    int tempNum = numerator;
    int tempDenom = denominator;
    if (denominator == other.denominator)
    {
        tempNum -= other.numerator;
    }
    else
    {
        tempNum = (numerator * other.denominator) - (other.numerator * denominator);
        tempDenom *= other.denominator;
    }
    return Simplify(tempNum, tempDenom);
}

Fraction Fraction::Multiply(Fraction other)
{
    return Simplify(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::Divide(Fraction other)
{
    return Simplify(numerator * other.denominator, denominator * other.numerator);
}

Fraction Fraction::Simplify(int num, int denom)
{
    int greatestCommonDivisor = GCD(num, denom);
    
    int tempNum = num;
    int tempDenom = denom;

    if (greatestCommonDivisor > 1)
    {
        tempNum /= greatestCommonDivisor;
        tempDenom /= greatestCommonDivisor;
    }

    return Fraction(tempNum, tempDenom);
}

void Fraction::Show()
{
    cout << numerator << "/" << denominator << endl;
}

int GCD(int a, int b)
{
    if (b <= 0)
    {
        return a;
    }
    else return GCD(b, a - (b * (a / b)));
}