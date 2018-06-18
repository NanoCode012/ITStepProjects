#pragma once

#include <iostream>

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(int num = 0, int denom = 1);
    Fraction(const Fraction &other);

    Fraction operator + (const Fraction &other);
    Fraction operator - (const Fraction &other);
    Fraction operator * (const Fraction &other);
    Fraction operator / (const Fraction &other);
    void operator = (const Fraction &other);

    void SetInitialValue(int num, int denom);

    Fraction Add(Fraction other);
    Fraction Subtract(Fraction other);
    Fraction Multiply(Fraction other);
    Fraction Divide(Fraction other);

    Fraction Simplify(int num, int denom);

    int Compare(int num);

    void Show();
};

int GCD(int a, int b);