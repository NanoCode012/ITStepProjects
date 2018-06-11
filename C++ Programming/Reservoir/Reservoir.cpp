#include "Reservoir.h"

using namespace std;

Reservoir::Reservoir(const char* name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Reservoir::Reservoir(const char* name, int width, int height, int depth, int type) : Reservoir(name)
{
    SetWidth(width);
    SetHeight(height);
    SetDepth(depth);
    SetType(type);
}

Reservoir::~Reservoir()
{
    if (name != NULL) delete[] name;
}

Reservoir::Reservoir(const Reservoir &other) : Reservoir(other.name, other.width, other.height, other.depth, other.type)
{

}

void Reservoir::SetWidth(int num)
{
    width = num;
}

void Reservoir::SetHeight(int num)
{
    height = num;
}

void Reservoir::SetDepth(int num)
{
    depth = num;
}

void Reservoir::SetType(int type)
{
    if (type == 0 || type == 1) this->type = type;
}

int Reservoir::GetWidth()
{
    return width;
}

int Reservoir::GetHeight()
{
    return height;
}

int Reservoir::GetDepth()
{
    return depth;
}

int Reservoir::GetType()
{
    return type;
}

int Reservoir::GetVolume()
{
    return (width * height * depth);
}

int Reservoir::GetSurfaceArea()
{
    return (width * height);
}

bool Reservoir::CheckIfSame(Reservoir &other)
{
    return (type == other.GetType());
}

void Reservoir::Output() const
{
    cout << "Width : " << width << endl
         << "Height : " << height << endl
         << "Depth : " << depth << endl;
}