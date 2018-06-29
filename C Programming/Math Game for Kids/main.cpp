#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    srand(time(NULL));

    const int limit = 15;
    const char* signs = "+-*/";

    int count = 0;
    for (int i = 0; i < 10; i++){
        int a = rand() % limit;
        int b = rand() % limit;
        
        int signInt = rand() % 4;
        int val;
        int userInput;
        
        switch(signInt){
            case 0: 
                val = a + b;
                break;
            case 1:
                val = a - b;
                break;
            case 2:
                val = a * b;
                break;
            case 3:
                val = a / b;
                break;
        }
        cout << a << " " << signs[signInt] << " " << b << " = ";
        
        cin >> userInput;
        if (userInput == val) count++;
    }
    cout << "You got " << count << " correct answer(s)." << endl;
    return 0;
}