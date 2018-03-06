#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "./Book.h"
#include "./Data.h"

using namespace std;

void ShowLine(){
    for (int i = 0; i < 50; i++) cout << '+';
    cout << endl;
}

void SetValuesToDefault(bool arr[], int length){
    for (int i = 0; i < length; i++) arr[i] = false;
}
void SetValuesToDefault(int arr[], int length){
    for (int i = 0; i < length; i++) arr[i] = i;
}

int main(){
    int length = 5;
    int opt, id;//for general
    string item;//for search
    bool hasIDItems[length];//for search
    int idArray[length];//for sort

    Book *books = new Book[length];
    LoadData(books);

    ShowLine();
    cout << "Welcome to my Library" << endl;

    while(true)
    {
        ShowLine();
        cout << "Options: "     << endl
             << "1. Print all"  << endl
             << "2. Edit"       << endl
             << "3. Search for "<< endl
             << "4. Sort for"   << endl
             << "5. Exit"       << endl;

        cout << "Please input option: ";
        cin >> opt;
        if (opt == 5) break;
        
        switch(opt)
        {
            case 1:
                PrintAll(books, length);
                break;
            case 2:
                cout << "Please enter item ID you want to edit: ";
                cin >> id;
                ShowLine();
                PrintHead();
                PrintAtIndex(books, id);
                PrintHeadOptions();
                cout << "Please enter which item you want to edit: ";
                cin >> opt;
                cout << "Please enter what you want to replace it with: ";
                cin >> item;
                EditItemAtID(books, id - 1, opt, item);
                break;
            case 3:
                PrintHeadOptions();
                cout << "Please enter which item you want to search: ";
                cin >> id;
                cout << "Please enter what you want to search: ";
                cin >> item;

                SetValuesToDefault(hasIDItems, length);
                PrintHead();
                if (SearchItem(books, hasIDItems, id, item, length))
                {
                    for (int i = 0; i < length; i++)
                    {
                        if (hasIDItems[i]){
                            PrintAtIndex(books, i + 1);
                        }
                    }
                }
                break;
            case 4:
                PrintHeadOptions();
                cout << "Please enter which item you want to sort: ";
                cin >> id;

                SetValuesToDefault(idArray, length);
                SortById(books, idArray, id, length);
                PrintHead();
                for (int i = 0; i < length; i++)
                {
                    PrintAtIndex(books, idArray[i] + 1);
                }
                break;
        }
    }
    
    return 0;
}