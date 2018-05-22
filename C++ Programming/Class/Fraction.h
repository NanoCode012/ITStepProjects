#pragma once

#include <iostream>

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    void SetInitialValue(int num, int denom);
    void Add(Fraction other);
    void Subtract(Fraction other);
    void Multiply(Fraction other);
    void Divide(Fraction other);
    void Show();
};