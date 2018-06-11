#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(int capacity)
{
    this->size = 0;
    if (capacity > 0) this->capacity = capacity;
    else this->capacity = 10;

    reservoirs = (Reservoir *)(malloc(sizeof(Reservoir) * capacity));
}

LinkedList::~LinkedList()
{
    cout << "Deleting Linkedlist" << endl;
    // free(reservoirs);//Might fail
}

LinkedList::LinkedList(const LinkedList &other) : LinkedList(other.capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        this->reservoirs[i] = other.reservoirs[i];
    }
}

void LinkedList::Insert(Reservoir r)
{
    if (size < capacity)
    {
        reservoirs[size] = r;
        size++;
    }
    else
    {
        Resize();
    }
}

void LinkedList::Delete(int index)
{
    if (index == 1 || index == size) size--;
    else if (1 < index && index < size)
    {
        reservoirs[index - 1] = reservoirs[size - 1];
        size--;
    }
    else
    {
        cout << "Not within range" << endl;
    }
}

void LinkedList::Resize()
{
    capacity *= 2;
    reservoirs = (Reservoir*)(realloc(reservoirs, sizeof(Reservoir) * capacity));
}

void LinkedList::SaveToFile(const char* path, bool saveAsText)
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
    }

    writeStream.close();
}