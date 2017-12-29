#include <iostream>

using namespace std;

int main(){
    int arr[5];
    for (int i = 0; i < 5; i++) arr[i] = i * 3 ;
    for (int i = 0; i < 5; i++) cout << arr[i] << endl;
    return 0;
}