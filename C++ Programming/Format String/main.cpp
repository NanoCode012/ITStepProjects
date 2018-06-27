#define _UNICODE
#include <iostream>
#include <tchar.h>
#include <stdarg.h>

using namespace std;

void Print(const TCHAR* format, ...)
{
    if (format == NULL) format = new TCHAR(0);

    va_list v1;
    va_start(v1, format);

    for (int i = 0; format[i + 1] != '\0'; i++)
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            switch(format[i + 1])
            {
                case 'd': wcout << va_arg(v1, int); i++; break;
                case 's': wcout << va_arg(v1, TCHAR*); i++; break;
                default: wcout << format[i];
            }
        }
        else wcout << format[i];
    }
    va_end(v1);


}

int main()
{
    Print(_TEXT("Print %d %s"), 13, _TEXT("CPol"));
    return 0;
}