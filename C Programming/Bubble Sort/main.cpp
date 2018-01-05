#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int swap(int arr[], int posA, int posB);

int main(){
    srand(time(NULL));
    const int size = 75;
    bool swapped = false;
    int arr[size];
    int timesToRun = size;//possible change to size -1 or -2.
    for (int i = 0; i < size; i++) arr[i] = rand() % 50;
    while(timesToRun-- > 0){
        swapped = false;
        for (int j = 1; j < size; j++){
            if (arr[j] < arr[j - 1]) {
                swap(arr, j - 1, j);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
    if (!swapped) cout << "Broke out" << endl;
    return 0;
}

int swap(int arr[], int posA, int posB){
    int temp = arr[posA];
    arr[posA] = arr[posB];
    arr[posB] = temp;
    return 0;
}