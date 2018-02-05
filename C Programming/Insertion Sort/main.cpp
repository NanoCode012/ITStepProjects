#include <iostream>

using namespace std;

int main(){
    const int length = 6;
    int nums[length] = { 6, 0, 10, 33, 7, 2};
    /*
    6, 0, 10

    */
    int x, j;
    for (int i = 0; i < length; i++)
    {
        x = nums[i];
        j = i - 1;//0
        while(j >= 0)
        {
            if (nums[j] > x)
            {
                nums[j + 1] = nums[j];
                nums[j] = x;
                j--;
            }else break;
        }
    }

    for (int k = 0; k < length; k++)
    {
        cout << nums[k] << " ";
    }
    cout << endl;
    return 0;
}