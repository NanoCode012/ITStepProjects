#pragma once

#include "Reservoir.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

class LinkedList
{
private:
    Reservoir* reservoirs;
    int size;
    int capacity;
public:
    LinkedList(int capacity = 10);
    ~LinkedList();

    LinkedList(const LinkedList &other);

    void Insert(Reservoir r);
    void Delete(int index);
    void Resize();

    void SaveToFile(const char* path = "Data.txt", bool saveAsText = true);
};