#include "SomeClass.h"

void* SomeClass::operator new (size_t size, const char* str)
{
    cout << "\n" << str << "\n";

    void* ptr = malloc(size);

    if (ptr) cout << "\nOK" << endl;
    else cout << "\nError" << endl;

    return ptr;
}

void* SomeClass::operator new[](size_t fullsize, const char* str)
{
    cout << "\n" << str << "\n";

    void* ptr = malloc(fullsize);

    if (ptr) cout << "\nOK []" << endl;
    else cout << "\nError []" << endl;

    return ptr;
}

void SomeClass::operator delete(void* ptr)
{
    free(ptr);
    cout << "\nDelete \n";
}

void SomeClass::operator delete[](void* ptr)
{
    free(ptr);
    cout << "\nDelete []\n";
}