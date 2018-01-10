#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int GetRandomNumber(int max){
    srand(time(NULL));
    return rand() % (max + 1);
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