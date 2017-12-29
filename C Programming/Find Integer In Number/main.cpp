#include <iostream>
#include <math.h>

using namespace std;

int main(){
    //Declare vars
    int input = 0;
    short a = 0;
    short max = 0;
    short i = 7;

    //Input
    cout << "Input: ";
    cin >> input;

    //Logic
Logic:
    a = input % 10; input /= 10; if (a > max) max = a;
    if (--i > 0) goto Logic;

    //Output
    cout << "The largest integer is " << max << endl;
    return 0;
}