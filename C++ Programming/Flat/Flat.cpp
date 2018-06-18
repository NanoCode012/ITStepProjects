#include "Flat.h"

using namespace std;

Flat::Flat(int area, int price)
{
    this->area = area;
    this->price = price;
}

bool Flat::operator== (const Flat &other)
{
    return (this->area == other.area);
}

void Flat::operator= (const Flat &other)
{
    this->area = other.area;
    this->price = other.price;
}

bool Flat::operator> (const Flat &other)
{
    return (this->price > other.price);
}

void Flat::Output()
{
    cout << "Area : " << area << endl;
    cout << "Price : " << this->price << endl;
}