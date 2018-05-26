#include <string>
#include <iostream>

// #define UNICODE
// #ifdef UNICODE
// #define TCHAR wchar_t
// // #define TEXT(string num) L+num
// #else 
// #define TCHAR char
// #define TEXT
// #endif

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

    wcout << "Found at : " << wcschr(str, 'o') << endl;
    
    //My own
    // TCHAR str2[50] = TEXT("Hi");
    return 0;

}