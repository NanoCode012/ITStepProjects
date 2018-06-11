#pragma once

#include <string.h>
#include <iostream>

class Reservoir
{
private:
    char* name;

    int width, height, depth, type;
public:
    Reservoir(const char* name = "");
    Reservoir(const char* name, int width, int height, int depth, int type);
    ~Reservoir();

    Reservoir(const Reservoir &other);

    void SetWidth(int num);
    void SetHeight(int num);
    void SetDepth(int num);
    void SetType(int type = 0);//0 = sea, 1 = pond

    int GetWidth();
    int GetHeight();
    int GetDepth();
    int GetType();
    
    int GetVolume();
    int GetSurfaceArea();

    bool CheckIfSame(Reservoir &other);

    void Output() const;
};