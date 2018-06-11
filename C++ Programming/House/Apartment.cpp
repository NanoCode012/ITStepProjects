#include "Apartment.h"

using namespace std;

Apartment::Apartment(int capacity)
{
    this->size = 0;
	if (capacity > 0) this->capacity = capacity;
	else this->capacity = 1;

	man = new Man[capacity];
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
		cout << "Success!" << endl;
    }
    else
    {
        cout << "Max capacity reached in Apartment" << endl;
    }
}

void Apartment::Remove(int index)
{
    /*if (index == 1 || index == size) 
	{
		size--;
		cout << "Success" << endl;
    else if (1 < index && index < size) 
    {
        this->man[index - 1] = man[--size];
		cout << "Success!" << endl;
    }
    else
    {
        cout << "Index not within range" << endl;
    }*/
	if (index < 1 || index > size)
	{
		cout << "Index not within range" << endl;
	}
	else
	{
		if (1 < index && index < size)
		{
			this->man[index - 1] = man[size - 1];
		}
		size--;
		cout << "Success!" << endl;
	}
}

void Apartment::Output(int index)
{
    if (1 <= index && index <= size)
    {
        cout << "ID : "    << index                    << endl
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
        cout << "Displaying Info about Man in apartment" << endl;
        for (int i = 0; i < size; i++)
        {
            Output(i + 1);
        }
        cout << "End Display" << endl;
    }
}

bool Apartment::IsFull()
{
    return (size >= capacity);
}