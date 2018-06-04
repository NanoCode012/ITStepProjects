#pragma once

#include <iostream>

class Binary
{
private:
    int num;
    int ConvertToBinary(int num);
public:
    Binary(int num = 0);
    Binary operator+(const Binary &other);
    Binary operator-(const Binary &other);
    Binary operator*(const Binary &other);
    Binary operator/(const Binary &other);

    void Print();
};