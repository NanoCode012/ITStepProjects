#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int ShiftHorizontal(bool shiftRight, int amount, int arr[2][6]){
    //create a new array which stores new value
    //set value from old array into correct position is new array
    //copy from new array back into old array
    int array[2][6];
    if (!shiftRight) amount *= -1;
    for (int i = 0; i < 6; i++){
        int position = (i + amount) % 6;
        if (position < 0) position += 6;
        array[0][position] = arr[0][i];
        array[1][position] = arr[1][i];
    }
    for (int i = 0; i < 6; i++){
        arr[0][i] = array[0][i];
        arr[1][i] = array[1][i];
    }
    return 0;
}
int ShiftVertical(bool shiftDown, int amount, int arr[2][6]){
    int array[2][6];
    if (!shiftDown) amount *= -1;
    for (int i = 0; i < 6; i++){
        int position = (amount) % 2;
        if (position < 0) position += 2;
        array[position][i] = arr[0][i];
        array[(position + 1) % 2][i] = arr[1][i];
    }
    for (int i = 0; i < 6; i++){
        arr[0][i] = array[0][i];
        arr[1][i] = array[1][i];
    }
    return 0;
}

int ShowArrays(int arr[2][6]){
    for (int i = 0; i < 6; i++) cout << arr[0][i%6] << " ";
    cout << endl;
    for (int i = 0; i < 6; i++) cout << arr[1][i%6] << " ";
    cout << endl;
    return 0;
}

int main(){
    srand(time(NULL));
    int arr[2][6];
    for (int i = 0; i < 12; i++) arr[i/6][i%6] = rand() % 20;
    ShowArrays(arr);
    char c;
    cin >> c;
    int amount;
    cin >> amount;
    switch(c)
    {
        case 'u':
            ShiftVertical(false, amount, arr);
            break;
        case 's':
            ShiftVertical(true, amount, arr);
            break;
        case 'a':
            ShiftHorizontal(false, amount, arr);
            break;
        case 'd':
            ShiftHorizontal(true, amount, arr);
            break;
    }
    ShowArrays(arr);
    return 0;
}