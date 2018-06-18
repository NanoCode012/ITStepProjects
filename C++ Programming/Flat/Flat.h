#pragma once

#include <iostream>

class Flat
{
private:
    int area;
    int price;
public:
    Flat(int area = 0, int price = 0);

    bool operator == (const Flat &other);
    void operator = (const Flat &other);
    bool operator > (const Flat &other);

    void Output();
};