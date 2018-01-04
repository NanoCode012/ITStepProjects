#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    srand(time(NULL));
    const int limit = 15;
    int count = 0;
    for (int i = 0; i < 10; i++){
        int a = rand() % limit;
        int b = rand() % limit;
        int signInt = rand() % 5;
        char sign;
        int val;
        int userInput;
        
        switch(signInt){
            case 0: 
                sign = '+';
                val = a + b;
                break;
            case 1:
                sign = '-';
                val = a - b;
                break;
            case 2:
                sign = '*';
                val = a * b;
                break;
            case 3:
                sign = '/';
                val = a / b;
                break;
            case 4:
                sign = '%';
                val = a % b;
                break;
        }
        cout << a << " " << sign << " " << b << " = ";
        
        cin >> userInput;
        if (userInput == val) count++;
    }
    cout << "You got " << count << " correct answer(s)." << endl;
    return 0;
}