#pragma once

#include <iostream>

#ifdef _UNICODE
#define TCHAR wchar_t*
#define TEXT(str) {(ConvertANSIToUnicode(str))}
#define OUT wcout
#else 
#define TCHAR (char*)
#define TEXT(str) {(GetChar(str))}
#define OUT cout
#endif

wchar_t* ConvertANSIToUnicode(const char * c);
const char* GetChar(const char * c);