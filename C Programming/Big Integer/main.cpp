#include <iostream>

using namespace std;

int main(){
    int n = 3;
    int temp = n;
    int length = 1;
    int arr[100];
    factorial(arr, 1);

    cout << arr[0] << endl;
    return 0;
}

void factorial(int a[], int num){
    a[0] = 1;
}

/*
 18
* 3
--- carry 2
 64 + carry
*/