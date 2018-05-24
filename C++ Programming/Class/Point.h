#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int ConvertFromStringToInt(string input);

class Point
{
private:
    int x;
    int y;
    int z;

public:
    Point();
    Point(int x, int y, int z);
    Point(const Point &p);
    void ShowCoordinates();
    inline int GetXCoordinate();
    inline int GetYCoordinate();
    inline int GetZCoordinate();
    void SaveCoordinatesToFileAtPath(string path);
    void ReadCoordinatesFromFileAtPath(string path);
};