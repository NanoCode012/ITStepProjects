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

String String::operator+(const String &other)
{
    char * c = new char[strlen(this->str) + strlen(other.str) + 1];
    strcpy(c, this->str);
    strcat(c, other.str);
    return String(c);
}

String String::operator-(const String &other)
{
    int lenA = strlen(this->str);
    int lenB = strlen(other.str);
    bool isSame = true;
    if (lenA >= lenB)
    {
        char * c = new char[lenA + 1];
        int currentIndex = 0;
        for (int i = 0; i < lenA; i++)
        {
            if(this->str[i] == other.str[0])
            {
                isSame = true;
                for (int j = 1; j < lenB && j < lenA; j++)
                {
                    if (this->str[i + (j)] != other.str[j])
                    {
                        isSame = false;
                    }
                }
                if (!isSame)
                {
                    c[currentIndex] = str[i];
                    currentIndex++;
                }
                else
                {
                    i += lenB - 1;//Skip the same part
                }
            }
            else
            {
                c[currentIndex] = str[i];
                currentIndex++;
            }
        }
        c[currentIndex] = '\0';
        return String(c);
    }
    else return String(this->str);
}

/*
String String::operator*(const String &other)
{
    int lenA = strlen(this->str);
    int lenB = strlen(other.str);
    int len = ((lenA > lenB) ? lenA : lenB);

    char *c = new char[len + 1];
    if (lenA > lenB)
    {

    }

}

String String::operator/(const String &other)
{
    int lenA = strlen(this->str);
    int lenB = strlen(other.str);

    char *c = new char[lenA + lenB + 1];

    int currentB = 0;
    int currentC = 0;

    bool isSame = false;
    for (int i = 0; i < lenA; i++)
    {
        isSame = false;
        for (int j = currentB; j < lenB; j++)
        {
            if (this->str[i] == other.str[j])
            {
                isSame = true;

            }
        }
    }
}
*/

void String::operator=(const String &other)
{
    delete []str;
    this->str = new char[strlen(other.str) + 1];
    strcpy(this->str, other.str);
}

String::~String()
{
    if (str != NULL)
    {
        delete []str;
        str = NULL;
    }
}

void String::Input(const char * c)
{
    strcpy(str, c);
}
void String::Output()
{
    cout << str << endl;
}