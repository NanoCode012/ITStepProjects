#pragma once

#include <iostream>

class A
{
private:
    int a;
public:
    A(int n = 0);

    A operator+(const A &other);
    A operator-(const A &other);
    A operator*(const A &other);
    A operator/(const A &other);

    void Output();
};