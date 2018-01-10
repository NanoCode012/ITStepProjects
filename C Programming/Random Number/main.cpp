#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int GetRandomNumber(){
    srand(time(NULL));
    return rand();
}

int GetRandomNumber(int max){
    return GetRandomNumber() % (max + 1);
}

int GetRandomNumber(int min, int max){
    return min + GetRandomNumber(max - min);
}


int main(){
    int a,b;
    cin >> a;
    cin >> b;
    cout << GetRandomNumber(a, b) << endl;
    return 0;
}