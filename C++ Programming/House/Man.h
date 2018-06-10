#pragma once

#include <string.h>
#include <iostream>

class Man
{
private:
    char* name;
    int age;
    void SetName(const char* name);
    void SetAge(int age);
public:
    Man();
    Man(const char* name, int age);
    Man(const Man &other);

    ~Man();

    void operator=(const Man &other);
    void operator delete[](void *p);
    
    void Copy(const Man &other);
    void Delete();
    
    char* GetName();
    int GetAge();
};