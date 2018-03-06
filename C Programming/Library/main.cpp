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

void SetAllToFalse(bool arr[], int length){
    for (int i = 0; i < length; i++) arr[i] = false;
}

int main(){
    int length = 5;
    int opt, id;
    string item;

    Book *books = new Book[length];
    bool hasIDItems[length];
    LoadData(books);

    ShowLine();
    cout << "Welcome to my Library" << endl;

    while(true)
    {
        ShowLine();
        cout << "Options: "      << endl
             << "1. Print all"  << endl
             << "2. Edit"       << endl
             << "3. Search for "<< endl
             << "4. Exit"       << endl;

        cout << "Please input option: ";
        cin >> opt;
        if (opt == 4) break;
        
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
                PrintHead();

                SetAllToFalse(hasIDItems, length);
                bool hasItem = SearchItem(books, hasIDItems, id, item, length);
                if (hasItem)
                {
                    for (int i = 0; i < length; i++)
                    {
                        if (hasIDItems[i]){
                            PrintAtIndex(books, i + 1);
                        }
                    }
                }
                break;
        }
    }
    
    return 0;
}