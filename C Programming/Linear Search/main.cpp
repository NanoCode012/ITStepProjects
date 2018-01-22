#include <iostream>
#include "../Random Number/Random.h"

using namespace std;

int main(){
    int size = GetRandomNumber(10);
    int arr[size];
    for (int i = 1; i <= size; i++){
        arr[i] = GetRandomNumber(30);
        cout << arr[i] << " ";
    }
    cout << endl;

    int key;
    cin >> key;
    for (int i = 1; i <= size; i++){
        if (arr[i] == key) {
            cout << "The key is at " << i << "th position." << endl;
        }
    }
    return 0;
}