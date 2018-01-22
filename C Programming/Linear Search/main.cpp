#include <iostream>
#include "../Random Number/Random.h"
#include "LinearSearch.h"

using namespace std;

int main(){
    int size = GetRandomNumber(10);
    int arr[size];
    for (int i = 0; i < size; i++){
        arr[i] = GetRandomNumber(30);
        cout << arr[i] << " ";
    }
    cout << endl;

    int key;
    cin >> key;
    cout << "Key is at " << LinearSearch(arr, key) + 1 << "th ." << endl;
    return 0;
}