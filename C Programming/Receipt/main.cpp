#include <iostream>

using namespace std;

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

int FindIndex(char products[], char key, int size)
{
    int index = -1;
    for (int i = 0; i < size; i++)
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

int SaveIntoCharacterArray(char products[], char input, int size)
{
    products[size] = input;
    return 0;
}

int SaveIntoReceipt(int arr[][2], int tempIndex, int size)
{
    arr[size][0] = tempIndex;
    arr[size][1] = 1;
    return 0;
}

int main(){

    const int capacity = 30;//capacity is the maximum size. size is the current size
    int size = 0;
    int arr[capacity][2];
    char products[capacity];

    cout << "Welcome!" << endl;

    char tempInput;
    int tempIndex;
    int duplicateId;
    while(true)
    {
        cout << "Please input item (0 to exit): ";
        cin >> tempInput;
        if (tempInput == '0') 
        {
            cout << "Exit.." << endl;
            break;
        }

        tempIndex = FindIndex(products, tempInput, size);
        if (tempIndex == -1)
        {
            SaveIntoCharacterArray(products, tempInput, size);
            SaveIntoReceipt(arr, size, size);//the id of the new item is the size
            size++;
        }else {
            arr[tempIndex][1] += 1;
        }
        OutputReceipt(arr, products, size);
    }
    return 0;
}