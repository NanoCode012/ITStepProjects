#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    Reservoir r("Corn", 2, 3, 4, 1);
    Reservoir r2("Seed", 2, 5, 2, 0);

    cout << r.GetVolume() << endl;
    cout << (r.CheckIfSame(r2) ? "true" : "false") << endl;

    LinkedList l(5);
    l.Insert(r);
    l.SaveToFile("Data.bin", false);
    return 0;
}