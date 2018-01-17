#include <iostream>
#define Fact(x) ((x <= 1) ? (1) : (x*Fact(x-1))) 
using namespace std;

int main(){
    cout << Fact(3) << endl;
    return 0;
}