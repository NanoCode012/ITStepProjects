#include "Tchar.h"

wchar_t* ConvertANSIToUnicode(const char * c)
{
    int len = mbstowcs(NULL, c, 0);
    wchar_t* ch = new wchar_t(len);
    mbstowcs(ch, c, len);
    return ch;
}

const char* GetChar(const char * c)
{
    return c;
}