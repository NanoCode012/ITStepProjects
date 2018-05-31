#include <iostream>
#include <string>


using namespace std;

string* SplitString(const char* c)
{
    int size = strlen(c);
    int len = 1;
    int i = 0;
    while(i < size && c[i] != '.')
    {
        if (c[i] == ' ') len++;
        i++;
    }

    string * arr = new string[len + 1];
    i = 0;
    int row = 0;
    while(i < size)
    {
        while(c[i] != ' ' && c[i] != '.')
        {
            arr[row] += c[i]; 
            i++;
        }
        row++;
        i++;
    }

    arr[row] = "NULL";
    return arr;
}

string* SplitString(const wchar_t* c)
{
    int size = wcslen(c);
    int len = 1;
    int i = 0;
    while(i < size && c[i] != '.')
    {
        if (c[i] == ' ') len++;
        i++;
    }

    string * arr = new string[len + 1];
    i = 0;
    int row = 0;
    while(i < size)
    {
        while(c[i] != ' ' && c[i] != '.')
        {
            arr[row] += c[i]; 
            i++;
        }
        row++;
        i++;
    }

    arr[row] = "NULL";
    return arr;
}

int main()
{
    //Split string with ANSI
    cout << "==ANSI==" << endl;

    char str[] = "There is a bird on the banana tree near an old house.";
    string * arr = SplitString(str);
    int i = 0;
    while(arr[i] != "NULL")
    {
        cout << arr[i] << endl;
        i++;
    }

    cout << endl;
    cout << "==UNICODE==" << endl;
    cout << endl;

    //Split string with Unicode
    wchar_t str2[] = L"There is a bird on the banana tree near an old house.";
    arr = SplitString(str2);
    i = 0;
    while(arr[i] != "NULL")
    {
        cout << arr[i] << endl;
        i++;
    }

    delete []arr;
}