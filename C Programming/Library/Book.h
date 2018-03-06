#include <iostream>
#include <string>
using namespace std;

struct Book{
    string title;
    string author;
    string publisher;
    string genre;
};

void PrintHead()
{
    cout << "ID"                << "\t"
         << "Title"             << "\t"     
         << "Author"            << "\t"     
         << "Publisher"         << "\t"     
         << "Genre"             << "\t"     
         << endl;
}

void PrintAtIndex(Book *books, int index)
{
    cout << index                       << "\t"
         << books[index - 1].title      << "\t"     
         << books[index - 1].author     << "\t"     
         << books[index - 1].publisher  << "\t\t"     
         << books[index - 1].genre      << "\t"     
         << endl;
}

void PrintAll(Book *books, int length){
    PrintHead();
    for (int i = 1; i <= length; i++)
    {
        PrintAtIndex(books, i);
    }
}

void PrintHeadOptions(){
    cout << "Option: "      << endl
         << "1. Title"      << endl
         << "2. Author"     << endl
         << "3. Publisher"  << endl
         << "4. Genre"      << endl;
}

int GetLength(string a){
    int i = 0;
    while(a[i] != '\0') i++;
    return i;
}
// bool Contains(string a, string b){
//     return (a.find(b) < 255) ? true : false;
// }

bool Contains(string source, string key)
{
    int lengthSource = GetLength(source);
    int lengthKey = GetLength(key);
    bool hasKey = false;
    if (lengthKey > lengthSource) return false;
    for (int i = 0; i < lengthSource-lengthKey + 1; i++)
    {
        for (int j = 0; j < lengthKey; j++){
            if (source[i + j] == key[j]) hasKey = true;
            else {
                hasKey = false;
                break;
            }
        }
        if (hasKey) return true;
    }
    return false;
}

// int SearchItem(Book *books, int itemID, string item, int length)
// {
//     switch(itemID)
//     {
//         case 1:
//             for (int i = 0; i < length; i++)
//             {
//                 if (Contains(books[i].title, item))
//                 {
//                     return i + 1;
//                 }
//             }
//             break;
//         case 2:
//             for (int i = 0; i < length; i++)
//             {
//                 if (Contains(books[i].author, item))
//                 {
//                     return i + 1;
//                 }
//             }
//             break;
//         case 3:
//             for (int i = 0; i < length; i++)
//             {
//                 if (Contains(books[i].publisher, item))
//                 {
//                     return i + 1;
//                 }
//             }
//             break;
//         case 4:
//             for (int i = 0; i < length; i++)
//             {
//                 if (Contains(books[i].genre, item))
//                 {
//                     return i + 1;
//                 }
//             }
//             break;
            
//     }
//     return -1;
// }

bool SearchItem(Book *books, bool bookHasItem[], int itemID, string item, int length)
{
    bool hasItem = false;
    switch(itemID)
    {
        case 1:
            for (int i = 0; i < length; i++)
            {
                if (Contains(books[i].title, item))
                {
                    bookHasItem[i] = true;
                    hasItem = true;
                }
            }
            break;
        case 2:
            for (int i = 0; i < length; i++)
            {
                if (Contains(books[i].author, item))
                {
                    bookHasItem[i] = true;
                    hasItem = true;
                }
            }
            break;
        case 3:
            for (int i = 0; i < length; i++)
            {
                if (Contains(books[i].publisher, item))
                {
                    bookHasItem[i] = true;
                    hasItem = true;
                }
            }
            break;
        case 4:
            for (int i = 0; i < length; i++)
            {
                if (Contains(books[i].genre, item))
                {
                    bookHasItem[i] = true;
                    hasItem = true;
                }
            }
            break;  
    }
    return hasItem;
}

void EditItemAtID(Book *books, int indexOfBook, int indexOfItem, string itemToReplaceWith)
{
    switch(indexOfItem)
    {
        case 1:
            books[indexOfBook].title = itemToReplaceWith;
            break;
        case 2:
            books[indexOfBook].author = itemToReplaceWith;
            break;
        case 3:
            books[indexOfBook].publisher = itemToReplaceWith;
            break;
        case 4:
            books[indexOfBook].genre = itemToReplaceWith;
            break;
    }
}




#pragma once