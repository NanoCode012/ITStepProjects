#include <iostream>
#include <string>

// #define _UNICODE
#include "Tchar.h"

using namespace std;

int main()
{
    //Unicode
    wchar_t str[50] = L"Hello";
    wcout << "Length : " << wcslen(str) << endl;

    wcscat(str, L" World");
    wcout << str << endl;

    wcscpy(str, L"Good!");
    wcout << str << endl;

    wcout << "Found 'o'! The letters afterword are : " << wcschr(str, 'o') << endl;
    
    //My own
    TCHAR str2 = TEXT("Hi");
    OUT << str2 << endl;
    cout << sizeof(str2) << endl;
    return 0;

}