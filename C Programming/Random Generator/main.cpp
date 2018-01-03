#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    srand(time(NULL));
    int a;
    for (int i = 0; i < 5; i++){
        a = rand();
        cout << a << endl;
        cout << a % 7 << endl; //get value from 0->7
        cout << a % 7 + 10 << endl; //get value from 10->17
    }

    
    return 0;


}