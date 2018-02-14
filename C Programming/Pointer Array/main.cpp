#include <iostream>

using namespace std;

int main(){
    int size;
    cout << "Please input size of array : ";
    cin >> size;

    //Initiated pointer array
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
        cout << arr[i] << " ";
    }

    //Clear memory
    delete []arr;

    cout << endl;

    return 0;
}