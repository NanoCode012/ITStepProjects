#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Person
{
    string name;
    string phone;
    string email;
};

void PrintLine()
{
    for (int i = 0; i < 50; i++) 
    {
        cout << "=";
    }
    cout << endl;
}

void PrintAtIndex(Person *person, int index)
{
    cout << "ID    : "      << index                     << endl
         << "Name  : "      << person[index - 1].name    << endl
         << "Phone : "      << person[index - 1].phone   << endl
         << "Email : "      << person[index - 1].email   << endl;
}

void PrintAll(Person *person, int size)
{
    for (int i = 1; i <= size; i++)
    {
        PrintLine();
        PrintAtIndex(person, i);
    }
    PrintLine();
}

void PrintFields()
{
    cout << "Options : "    << endl
         << "1. Name"       << endl
         << "2. Phone"      << endl
         << "3. Email"      << endl;
}

int Power(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++) result *= base;
    return result;
}

void Copy(Person *source, Person *dest, int index)
{
    dest[index].name = source[index].name;
    dest[index].phone = source[index].phone;
    dest[index].email = source[index].email;
}

void Copy(Person source, Person *dest, int index)
{
    dest[index].name = source.name;
    dest[index].phone = source.phone;
    dest[index].email = source.email;
}

void Resize(Person *(&person), int &capacity, int multiplier = 2, bool copyPreviousData = true)
{
    int size = capacity;
    capacity *= multiplier;
    Person *newPerson = (struct Person *)realloc(person, capacity * sizeof(Person));
    if (!newPerson) 
    {
        cout << "An error occurred while reallocating!" << endl;
        exit(-1);
    }
    if (copyPreviousData)
    {
        for (int i = 0; i < size; i++)
        {
            Copy(person, newPerson, i);
        }
    }
    person = newPerson;
}

void ReadFromFile(Person *(&person), int &size, int &capacity, string path)
{
    ifstream readStream(path);
    if (!readStream.is_open())
    {
        cout << "Cannot read file" << endl;
    }
    else
    {
        string temp;
        if (!getline(readStream, temp)) 
        {
            cout << "Error! Empty File!" << endl;
        }
        else
        {
            int length = temp.length();
            for (int i = 0; i < length; i++)
            {
                capacity += (int)(temp[i] - '0') * Power(10, length - i - 1);
            }
            person = new Person[capacity];
            int k = 0;
            while (getline(readStream, temp)) 
            {
                size++;

                int j = 0;
                while(temp[j] != ' ') { person[k].name += temp[j];  j++; } 
                j++;
                while(temp[j] != ' ') { person[k].phone += temp[j]; j++; } 
                j++;
                while(temp[j] != ' ') { person[k].email += temp[j]; j++; } 
                k++;
            }    
        }
    }
    readStream.close();
}

void WriteToFile(Person *person, int size, string path)
{
    ofstream writeStream;
    writeStream.open(path);
    writeStream << size << endl;
    for (int i = 0; i < size; i++)
    {
        writeStream << person[i].name << " " << person[i].phone << " " << person[i].email << " " << endl;
    }
    writeStream.close();
}

void Add(Person *person, Person personToAdd, int &size, int &capacity)
{
    if (size == capacity) Resize(person, capacity);
    Copy(personToAdd, person, size);
    size++;
}

bool Contains(string source, string key)
{
    int lengthSource = source.length();
    int lengthKey = key.length();
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

bool SearchItem(Person *person, bool *hasItem, int itemID, string itemToSearch, int size)
{
    bool containItem = false;
    switch(itemID)
    {
        case 1:
            for (int i = 0; i < size; i++)
            {
                if (Contains(person[i].name, itemToSearch))
                {
                    hasItem[i] = true;
                    containItem = true;
                }
            }
            break;
        case 2:
            for (int i = 0; i < size; i++)
            {
                if (Contains(person[i].phone, itemToSearch))
                {
                    hasItem[i] = true;
                    containItem = true;
                }
            }
            break;
        case 3:
            for (int i = 0; i < size; i++)
            {
                if (Contains(person[i].email, itemToSearch))
                {
                    hasItem[i] = true;
                    containItem = true;
                }
            }
            break;
    }
    return containItem;
}

void EditItem(Person *person, int id, int itemID, string itemToReplaceWith)
{
    switch(itemID)
    {
        case 1:
            person[id - 1].name = itemToReplaceWith;
            break;
        case 2:
            person[id - 1].phone = itemToReplaceWith;
            break;
        case 3:
            person[id - 1].email = itemToReplaceWith;
            break;
    }
}


#pragma once

