#pragma once

#include <iostream>
#include "Man.h"

class Apartment
{
private:
    Man *man;
    int size;
    int capacity;
public:
    Apartment(int capacity = 1);
    Apartment(const Apartment &other);
    ~Apartment();

    void operator=(const Apartment &other);
    void operator delete[](void *p);

    void Copy(const Apartment &other);
    void Delete();
    
    void Add(Man newMan);
    void Remove(int index);
    void Output(int index);
    void OutputAll();
    bool IsFull();
};