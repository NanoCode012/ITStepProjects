#include <iostream>

using namespace std;
int main(){
    
    int a = 0;
    int b = 0;
    int attempt = 0;

StartApplication:
    attempt++;
    cout << "Input a : " ;
    cin >> a;
    cout << "Input b : " ;
    cin >> b;
    
    if (a > b) {
        cout << "a is bigger" << endl;
    }else if (a == b){
        cout << "a equal to b" << endl;
    }else if (a < b){
        cout << "b is bigger" << endl;
    }
    char passOn = 'N';
    if (attempt <= 2){ //runs this block max 2 times
        cout << "Do you want to continue? Y or N : " ;
        cin >> passOn;
        if (passOn == 'Y'){
            goto StartApplication;
        }else cout << "Exiting now....";
    }
    return 0;
}