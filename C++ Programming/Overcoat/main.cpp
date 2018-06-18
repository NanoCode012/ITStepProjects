#include <iostream>
#include "Overcoat.h"

using namespace std;

int main()
{
    Overcoat o (1, 100); 
    o.Output();
    
    Overcoat o2 (4, 90); 
    o2.Output();
    
    cout << ((o == o2) ? "o and o2 is the same type" : "o and o2 is not the same type") << endl;
    cout << ((o > o2) ? "o costs more than o2" : "o2 costs more than o") << endl;

    Overcoat o3;
    o3 = o;
    o3.Output();
    system("pause");
    return 0;
}