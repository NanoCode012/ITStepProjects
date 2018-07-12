#include "stdafx.h"
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

	//Simplify the negatives
	if ((tempNum < 0 && tempDenom < 0) || (tempNum > 0 && tempDenom < 0))
	{
		tempNum *= -1;
		tempDenom *= -1;
	}
    return Fraction(tempNum, tempDenom);
}

int Fraction::Compare(int num)
{
    if (numerator > num) return 1;
    else if (numerator == num) return 0;
    else return -1;
}

void Fraction::Show()
{
	if (denominator != 1)
	{
		cout << numerator << "/" << denominator;
	}
	else
	{
		cout << numerator;
	}
}

float Fraction::GetValue()
{
	return ((float)numerator/ (float)denominator);
}

int GCD(int a, int b)
{
    if (b <= 0)
    {
        return a;
    }
    else return GCD(b, a - (b * (a / b)));
}