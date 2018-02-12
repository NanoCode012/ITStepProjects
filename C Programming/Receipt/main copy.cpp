#include <iostream>

using namespace std;

int InitializeEmptyIntegerArray(int arr[][2], int capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        arr[i][0] = 0;
        arr[i][1] = 0;
    }
    return 0;
}

int OutputReceipt(int arr[][2], char products[], int size)
{
    if (size > 0)
    {
        cout << "Name\tCount" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << products[arr[i][0]] << "\t" << arr[i][1] << endl;
        }
    }
    return 0;
}

int FindIndex(char products[], char key, int capacity)
{
    int index = -1;
    for (int i = 0; i < capacity; i++)
    {
        if (products[i] == key) 
        {
            index = i;
            break;
        }
    }
    return index;
}

int FindDuplicate(int arr[][2], int tempIndex, int size)
{
    int duplicateId = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i][0] == tempIndex)
        {
            duplicateId = i;
        }
    }
    return duplicateId;
}

int main(){

    const int capacity = 30;//capacity is the maximum size. size is the current size
    int size = 0;
    int arr[capacity][2];
    char products[capacity] = {'A', 'B', 'C', 'D', 'E'};
    
    InitializeEmptyIntegerArray(arr, capacity);

    cout << "Welcome!" << endl;

    char tempInput;
    int tempIndex;
    int duplicateId;
    while(true)
    {
        cout << "Please input item (A->E)(Anything else to exit): ";
        cin >> tempInput;

        tempIndex = FindIndex(products, tempInput, capacity);
        if (tempIndex == -1)
        {
            cout << "Exiting .." << endl;
            break;
        }else {
            duplicateId = FindDuplicate(arr, tempIndex, size);
            if (duplicateId == -1)
            {
                arr[size][0] = tempIndex;
                arr[size][1] = 1;
                size++;
            }else {
                arr[duplicateId][1] += 1;
            }
            OutputReceipt(arr, products, size);
        }

    }
    return 0;
}