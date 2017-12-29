#include <iostream>
#include "logic.h"

using namespace std;

int main(){
    float a = 0;
    a = CalculateTax(8500000);
    if (724999 <= a && a <= 725000) {
        return 0;
    }
    else{
        return -1;  
    } 
}

   

