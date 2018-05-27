#include "String.h"

using namespace std;

String::String(int length)
{
    str = new char[length];
}
String::String(const char * c) : String(strlen(c) + 1)//Constructor delegation
{
    strcpy(str, c);
}
String::String(const String &other) : String(other.str)
{
}

String::~String()
{
    delete []str;
}

void String::Input(const char * c)
{
    strcpy(str, c);
}
void String::Output()
{
    cout << str << endl;
}