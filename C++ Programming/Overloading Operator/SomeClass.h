#pragma once

#include <iostream>

using namespace std;

class SomeClass
{
private:
    int some;
public:
    void* operator new(size_t size, const char *str = "New");
    void* operator new[](size_t fullSize, const char* str = "New []");

    void operator delete(void* ptr);
    void operator delete[](void* ptr);
};