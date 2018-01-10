#include <iostream>
#include "Random.h"

using namespace std;

int main(){
    int a,b;
    cin >> a;
    cin >> b;
    cout << GetRandomNumber(a, b) << endl;
    return 0;
}