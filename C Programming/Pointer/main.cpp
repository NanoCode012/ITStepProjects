#include <iostream>

using namespace std;

void OutputElement(int *num, int size){
    for (int i = 0; i < size; i++)
    {
        cout << *(num + i) << " is at address " << (num + i) << endl;
    }
}

int main(){
    const int size = 5;
    int nums[size] = {1,5,10,15,20};
    int *p = &nums[0];

    for (int i = 0; i < size; i++)
    {
        cout << *(p + i) << " is at address " << (p + i) << endl;
    }
    delete p;//remove the pointer from RAM

    cout << endl;

    //Pass Array as pointer
    OutputElement(nums, size);
    return 0;
}