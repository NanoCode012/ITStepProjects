#include <iostream>
#include <math.h>

using namespace std;

int main(){
    //Declare
    float a, b, c;
    float delta = 0;
    float rootOne, rootTwo;

    bool canContinue = true;
    
    //Input
AppStart:
    cout << "a*x^2 + b*x + c = 0" << endl;
    cout << "====================" << endl;
    cout << "Please enter a: ";
    cin >> a;
    if (a == 0) goto AppStart;
    cout << "Please enter b: ";
    cin >> b;
    cout << "Please enter c: ";
    cin >> c;

    //Logic
    delta = (powf(b,(float)2)) - (4 * a * c);
    if (delta < 0){
        cout << "Root of Delta less than 0. Can only compute in complex." << endl;
        canContinue = false;
    }else if (delta == 0){
        cout << "Root of Delta equal to 0. Only one root." << endl;
    }else if (delta > 0){
        cout << "Root of Delta larger than 0. Can compute in current range." << endl;
    }

    if (canContinue){
        delta = sqrtf(delta);
        rootOne = ((-b) + delta) / 2*a;
        rootTwo = ((-b) - delta) / 2*a;
        cout << "One root is : " << rootOne << endl;
        if (delta > 0){
            cout << "The other root is : " << rootTwo << endl;
        }
        

    }
    return 0;
}