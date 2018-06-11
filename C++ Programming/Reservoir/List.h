#pragma once

#include "Reservoir.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

class List
{
private:
    Reservoir* reservoirs;
    int size;
    int capacity;
public:
    List(int capacity = 10);
    ~List();

    List(const List &other);

    void Insert(Reservoir r);
    void Remove(int index);
    void Resize();

	int GetVolume(int index);
	int GetSurfaceArea(int index);
	int GetType(int index);
	int GetSize();

	void Output(int index);
	void OutputAll();

    void SaveToFile(const char* path = "Data.txt", bool saveAsText = true);
};