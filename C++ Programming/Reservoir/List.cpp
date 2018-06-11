#include "List.h"

using namespace std;

List::List(int capacity)
{
    this->size = 0;
    if (capacity > 0) this->capacity = capacity;
    else this->capacity = 10;

    reservoirs = (Reservoir *)(malloc(sizeof(Reservoir) * capacity));
}

List::~List()
{
    cout << "Deleting Linkedlist" << endl;
    free(reservoirs);//Might fail
}

List::List(const List &other) : List(other.capacity)
{
	this->size = other.size;
    for (int i = 0; i < size; i++)
    {
        this->reservoirs[i] = other.reservoirs[i];
    }
}

void List::Insert(Reservoir r)
{
    if (size >= capacity)
    {
        Resize();
    }
    reservoirs[size] = r;
    size++;

	cout << "Success!" << endl;
}

void List::Remove(int index)
{
    /*if (index == 1 || index == size) size--;
    else if (1 < index && index < size)
    {
        reservoirs[index - 1] = reservoirs[size - 1];
        size--;
    }
    else
    {
        cout << "Not within range" << endl;
    }*/
	if (index < 1 || index > size)
	{
		cout << "Index not within range" << endl;
	}
	else
	{
		if (1 < index && index < size)
		{
			this->reservoirs[index - 1] = reservoirs[size - 1];
		}
		size--;
		cout << "Success!" << endl;
	}
}

void List::Resize()
{
    capacity *= 2;
    reservoirs = (Reservoir*)(realloc(reservoirs, sizeof(Reservoir) * capacity));
}

int List::GetVolume(int index)
{
	return reservoirs[index - 1].GetVolume();
}

int List::GetSurfaceArea(int index)
{
	return reservoirs[index - 1].GetSurfaceArea();
}

int List::GetType(int index)
{
	return reservoirs[index - 1].GetType();
}

int List::GetSize()
{
	return size;
}

void List::Output(int index)
{
	if (1 <= index && index <= size)
	{
		cout << "Index : " << index << endl;
		reservoirs[index - 1].Output();
	}
	else cout << "Index not within range" << endl;
}

void List::OutputAll()
{
	for (int i = 1; i <= size; i++)
	{
		Output(i);
	}
}

void List::SaveToFile(const char* path, bool saveAsText)
{
    ofstream writeStream(path);

    int len = 100;
    int base = (saveAsText) ? 10 : 2;
    char * buffer = new char[len];

    _itoa(size, buffer, base);
    writeStream << buffer << endl;

    _itoa(capacity, buffer, base );
    writeStream << buffer << endl;

    for(int i = 0; i < size; i++)
    {
        _itoa(reservoirs[i].GetWidth(), buffer, base);
        writeStream << buffer << " ";
        
        _itoa(reservoirs[i].GetHeight(), buffer, base);
        writeStream << buffer << " ";
        
        _itoa(reservoirs[i].GetDepth(), buffer, base);
        writeStream << buffer << " ";

        _itoa(reservoirs[i].GetType(), buffer, base);
        writeStream << buffer << " ";

		writeStream << endl;
    }

    writeStream.close();
}