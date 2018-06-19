#include <iostream>
#include "Date.h"

using namespace std;

int main(){
    
    Date d1(5, 5, 2015);
    Date d2(10, 3, 2018);

    cout << d2 - d1 << endl;

    Date d3;
    d3 = d1 + 30;
    d3.Output();
    
    return 0;
}