#include <iostream>

using namespace std;

int main(){
    int base = 0;
    int num = 1;
    cout << "Please enter number : ";
    cin >> base;
    
    cout << base << " ^ " << 0 << " = " << num << endl;
    for (int i = 1; i <= 7; i++){
        num *= base;
        cout << base << " ^ " << i <<  " = " << num << endl;;
    }
    cout << endl;

    num = 1;
    int j = 0;
    do{
        cout << base << " ^ " << j <<  " = " << num << endl;
        num *= base;
    }while(++j <= 7);
    cout << endl;

    num = 1;
    int tempNum = 0;
    for (int k = 0; k < 7; k++){
        tempNum = k;
        num *= base;
        cout << base;
        while(tempNum-- > 0) cout << " * " << base;
        cout << " = " << num << endl;
    }
    return 0;
}