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

int Compare(string a, string b){
    // a.compare(b); didn't realize they had this
    int def = 0;
    int length = a.length();
    if (b.length() < length) {//the shorter one is the second
        length = b.length();
        def = 1;
    }else if (b.length() > length)//the shorter one is the first
    {
        def = -1;
    }
    for (int i = 0; i < length; i++){
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }
    return def;
}

void Swap(string arr[], int id[], int a, int b){
    string temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;

    int tempB = id[a];
    id[a] = id[b];
    id[b] = tempB;
}

void Sort(string *arr, int id[], int size, int(*cmp)(string a, string b)){
    //Selection Sort
    for (int i = 0; i < size; i++)
    {
        int index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (cmp(arr[index], arr[j]) > 0) index = j;
        }
        Swap(arr, id, i, index);
    }
}

void SortById(Book *books, int id[], int item, int length)
{
    string *arr = new string[length];
    switch(item)
    {
        case 1:
            for (int i = 0; i < length; i++)
            {
                arr[i] += books[i].title;
            }
            break;
        case 2:
            for (int i = 0; i < length; i++)
            {
                arr[i] += books[i].author;
            }
            break;
        case 3:
            for (int i = 0; i < length; i++)
            {
                arr[i] += books[i].publisher;
            }
            break;
        case 4:
            for (int i = 0; i < length; i++)
            {
                arr[i] += books[i].genre;
            }
            break;
    }
    Sort(arr, id, length, Compare);
    delete[] arr;
}

#pragma once