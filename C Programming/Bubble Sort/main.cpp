#include <iostream>
#include "../Random Number/Random.h"
#include "BubbleSort.h"
using namespace std;

int main(){
    srand(time(NULL));
    const int size = 75;
    bool swapped = false;
    int arr[size];
    for (int i = 0; i < size; i++) arr[i] = GetRandomNumber(50);
    BubbleSort(arr, size);
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
