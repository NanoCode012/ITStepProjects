#include "Overcoat.h"

using namespace std;

Overcoat::Overcoat(int type, int price)
{
    this->type = type;
    this->price = price;
}

bool Overcoat::operator== (const Overcoat &other)
{
    return (this->type == other.type);
}

void Overcoat::operator= (const Overcoat &other)
{
    this->type = other.type;
    this->price = other.price;
}

bool Overcoat::operator> (const Overcoat &other)
{
    return (this->price > other.price);
}

void Overcoat::Output()
{
    cout << "Type : ";
    switch(this->type)
    {
        case 0:
            cout << "Chesterfield";
            break;
        case 1:
            cout << "Covert Coat";
            break;
        case 2:
            cout << "Trench Coat";
            break;
        case 3:
            cout << "Paletot";
            break;
        case 4:
            cout << "Guards Coat";
            break;
        case 5:
            cout << "Ulster";
            break;
        case 6:
            cout << "Polo Coat";
            break;
    }
    cout << endl;

    cout << "Price : " << this->price << endl;
}