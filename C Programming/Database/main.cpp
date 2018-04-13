#include <iostream>
#include "./Person.h"
#include <thread>
#include <chrono>

using namespace std;

void SetValueToDefault(bool *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = false;
    }
}

/*
void Loading(){
    
    // string a = "✈";
    //string left = "▶";
    // string right = "◀";
    // string b = "•";
    string left = "■";
    string right = "■";
    string b = "□";
    for (int k = 0; k < 2; k++)
    {
        int index = 0;
        for (int j = 0; j < 5; j++)
        {
            system("clear");
            for (int i = 0; i < 5; i++)
            {
                if (i == index) cout << left;
                else cout << b;
            }
            cout << endl;
            index++;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        index--;
        for (int j = 0; j < 5; j++)
        {
            system("clear");
            for (int i = 0; i < 5; i++)
            {
                if (i == index) cout << right;
                else cout << b;
            }
            cout << endl;
            index--;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
    system("clear");
}
*/

int main(){
    int size = 0;
    int capacity = 3;
    string path = "./contact.txt";
    Person *person = (struct Person*)malloc(capacity * sizeof(struct Person));
    //For adding new contact
    Person newPerson;
    //For general I/O
    char answer;
    int opt, index;
    //For searching
    string item;
    bool *hasItem;

    PrintLine();
    cout << "Welcome to the Database" << endl;
    
    cout << "Would you like to read from file? Answer(Y/N) : ";
    cin >> answer;
    if (answer == 'Y' || answer == 'y') 
    {
        ReadFromFile(person, size, capacity, path);
        // Loading();
        cout << "Successfully loaded data from file!" << endl;
    }
    else
    {
        cout << "Did not load data from file." << endl;
    }
    while(true)
    {
        PrintLine();
        cout << "What would you like to do?"    << endl
             << "Options: "                     << endl
             << "1. Show Existing Contacts"     << endl
             << "2. Add a new contact"          << endl
             << "3. Search contact(s)"          << endl
             << "4. Edit contact"               << endl
             << "5. Save to file"               << endl
             << "6. Exit"                       << endl;
        cout << "Opt : ";
        cin >> opt;
        if (opt == 6) 
        {
            cout << "Do you want to save to file? Answer(Y/N) : ";
            cin >> answer;
            if (answer == 'Y' || answer == 'y') 
            {
                WriteToFile(person, size, path);
                // Loading();
                cout << "Successfully saved to file!" << endl;
            }
            else 
            {
                cout << "Did not save data to file." << endl;
            }
            break;
        }
        switch(opt)
        {
            case 1:
                // Loading();
                PrintAll(person, size);
                break;
            case 2:
                cout << "Please enter name of new contact : ";
                cin >> newPerson.name;
                cout << "Please enter phone number of new contact : ";
                cin >> newPerson.phone;
                cout << "Please enter email of new contact : ";
                cin >> newPerson.email;
                Add(person, newPerson, size, capacity);
                // Loading();
                cout << "Successfully added!" << endl;
                break;
            case 3:
                PrintFields();
                cout << "Please enter ID of the field you wish to search : ";
                cin >> opt;
                cout << "Search : ";
                cin >> item;
                hasItem = new bool[size];
                SetValueToDefault(hasItem, size);
                // Loading();
                if (SearchItem(person, hasItem, opt, item, size))
                {
                    for (int i = 0; i < size; i++) 
                    {
                        if (hasItem[i]) 
                        {
                            PrintLine();
                            PrintAtIndex(person, i + 1);
                        }
                    }
                    PrintLine();
                }
                else
                {
                    cout << "No similar item found." << endl;
                }
                break;
            case 4:
                cout << "Please enter the ID of the contact you wish to edit : ";
                cin >> index;
                PrintLine();
                PrintAtIndex(person, index);
                PrintLine();
                PrintFields();
                cout << "Please enter ID of the field you wish to edit : ";
                cin >> opt;
                cout << "Change to : ";
                cin >> item;
                EditItem(person, index, opt, item);
                // Loading();
                cout << "Successfully edited contact!" << endl;
                break;
            case 5:
                WriteToFile(person, size, path);
                cout << "Successfully saved to file!" << endl;
        }
    }
    delete []hasItem;
    return 0;
}