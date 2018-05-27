#pragma once

#include <iostream>
#include <string.h>

class String
{
private:
    char *str;
    int length;
public:
    String(int length = 80);
    String(const char * c);
    String(const String &str);

    ~String();

    void Input(const char * c);
    void Output();
};