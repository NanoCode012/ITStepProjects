#pragma once

#include <string.h>
#include <iostream>

class Man
{
private:
    char* name;
    int age;
public:
    Man();
    Man(const char* name, int age);
    Man(const Man &other);

    ~Man();

    void operator=(const Man &other);
    
    void Copy(const Man &other);
    
    char* GetName();
    int GetAge();

    void SetName(const char* name);
    void SetAge(int age);

};