#include <iostream>

using namespace std;

int main(){
    int a;
    int size = 0;
    char num[100];
    cout << "Input num : ";
    cin >> a;
    while(a > 0)
    {
        if (a & 1) num[size++] = '1';
        else num[size++] = '0';
        a >>= 1;
    }

    for (int i = size; i >= 0; i--)
    {
        cout << num[i];
    }

    cout << endl;

    return 0;
}