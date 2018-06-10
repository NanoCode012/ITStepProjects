#include "Apartment.h"

using namespace std;

Apartment::Apartment(int capacity)
{
    this->size = 0;
    if (capacity > 0) this->capacity = capacity;
    else this->capacity = 1;
}

Apartment::Apartment(const Apartment &other)
{
    Copy(other);
}

Apartment::~Apartment()
{
    if (man != NULL)
    {
        cout << "Deleting Apartment" << endl;
        delete[] man;
    }
    else
    {
        cout << "Apartment's Man is already NULL" << endl;
    }
}

void Apartment::operator=(const Apartment &other)
{
    Copy(other);
}

void Apartment::Copy(const Apartment &other)
{
    this->man = new Man[other.capacity];
    int len = other.size;
    for(int i = 0; i < len; i++) 
    {
        this->man[i] = other.man[i];
    }
}

void Apartment::Add(Man newMan)
{
    if (size < capacity)
    {
        this->man[size++] = newMan;
    }
    else
    {
        cout << "Max capacity reached in Apartment" << endl;
    }
}

void Apartment::Delete(int index)
{
    if (index == 1 || index == size) size--;
    else if (1 < index && index < size) 
    {
        this->man[index - 1] = man[size - 1];
        size--;
    }
    else
    {
        cout << "Index not within range" << endl;
    }
}

void Apartment::Output(int index)
{
    if (1 <= index && index <= size)
    {
        cout << "Index : " << index                    << endl
             << "Name  : " << man[index - 1].GetName() << endl
             << "Age   : " << man[index - 1].GetAge()  << endl;
    }
    else
    {
        cout << "Index not within range" << endl;
    }
}

void Apartment::OutputAll()
{
    if (size > 0)
    {
        for (int i = 0; i < size; i++)
        {
            Output(i + 1);
        }
    }
}

bool Apartment::IsFull()
{
    return (size >= capacity);
}