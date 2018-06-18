#pragma once

#include <iostream>
#include "Fraction.h"

class Complex
{
    //Form : a + b * i
private:
    Fraction a;
    Fraction b;
public:
    Complex(int a, int b);
    Complex(Fraction a, Fraction b);

    Complex operator + (const Complex &other);
    Complex operator - (const Complex &other);
    Complex operator * (const Complex &other);
    Complex operator / (const Complex &other);

    void Output();
};