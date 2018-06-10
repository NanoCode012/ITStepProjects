#pragma once

#include <iostream>
#include "Apartment.h"

class House
{
private:
    Apartment *apartment;
    bool* occupancy;
    int capacity;
public:
    House(int capacity = 1);
    House(const House &other);
    ~House();

    void operator=(const House &other);

    void Copy(const House &other);
    void Delete();

    void SetFilledStatus(int index, bool isFilled = true);
    bool GetFilledStatus(int index);

    void Add(int index, Man man);
    void Remove(int index, int indexMan = 1);
    void Output(int index);
    void OutputAll();
};