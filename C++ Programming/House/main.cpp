#include <iostream>
#include "House.h"

using namespace std;

int main()
{
    House house(5);
    Man man("Horn", 12);
    
    cout << "Adding man" << endl;
    house.Add(1, man);
    house.OutputAll();

    cout << "Removing man at apartment 1" << endl;
    house.Remove(1);
    house.OutputAll();
    return 0;
}
