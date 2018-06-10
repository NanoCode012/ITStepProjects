#include "House.h"

using namespace std;

House::House(int capacity)
{
    this->capacity = capacity;
    occupancy = new bool[capacity];
    apartment = new Apartment[capacity];
}

House::House(const House &other)
{
    Copy(other);
}

House::~House()
{
    if (occupancy != NULL)
    {
        cout << "Deleting House's occupancy" << endl;
        delete[] occupancy;
    }
    else
    {
        cout << "House's occupancy is NULL" << endl;
    }

    if (apartment != NULL)
    {
        cout << "Deleting House's apartment" << endl;
        delete[] apartment;
    }
    else
    {
        cout << "House's apartment is NULL" << endl;
    }
}

void House::operator=(const House &other)
{
    Copy(other);
}

void House::Copy(const House &other)
{
    int len = other.capacity;

    this->apartment = new Apartment[len];
    this->occupancy = new bool[len];

    for (int i = 0; i < len; i++)
    {
        this->apartment[i] = other.apartment[i];
        this->occupancy[i] = other.occupancy[i];
    }
}

void House::SetFilledStatus(int index, bool isFilled)
{
    if (1 <= index && index <= capacity)
    {
        occupancy[index - 1] = isFilled;
    }
    else
    {
        cout << "Index not within range" << endl;
    }
}

bool House::GetFilledStatus(int index)
{
    if (1 <= index && index <= capacity)
    {
        return occupancy[index - 1];
    }
    else
    {
        cout << "Index not within range" << endl;
        return false;
    }
}

void House::Add(int index, Man man)
{
    if (1 <= index && index <= capacity)
    {
        apartment[index - 1].Add(man);
    }
    else
    {
        cout << "Index not within range" << endl;
    }
}

void House::Remove(int index, int indexMan)
{
    if (1 <= index && index <= capacity)
    {
        apartment[index - 1].Delete(indexMan);
    }
    else
    {
        cout << "Index not within range" << endl;
    }
}

void House::Output(int index)
{
    bool hasOccupants = GetFilledStatus(index);
    cout << "Index : "  << index                    << endl
         << "Status : " << ( hasOccupants ? "Has occupants" : "Vacant")  << endl;
    if (hasOccupants)
    {
        apartment[index - 1].OutputAll();
    }
}

void House::OutputAll()
{
    for (int i = 1; i <= capacity; i++)
    {
        Output(i);
    }
}