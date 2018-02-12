#include <iostream>

using namespace std;

int main(){
    const int size = 5;
    int nums[size] = {1,5,10,15,20};
    int *p = &nums[0];

    for (int i = 0; i < size; i++)
    {
        cout << *(p + i) << " is at address " << (p + i) << endl;
    }
    return 0;
}