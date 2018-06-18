#pragma once

#include <iostream>

class Overcoat
{
private:
    int type;//0 : Chesterfield , 1 : Covert Coat , 2 : Trench Coat , 3 : Paletot, 4 : Guards Coat , 5 : Ulster , 6 : Polo Coat
    int price;
public:
    Overcoat(int type = 0, int price = 0);

    bool operator == (const Overcoat &other);
    void operator = (const Overcoat &other);
    bool operator > (const Overcoat &other);

    void Output();
};