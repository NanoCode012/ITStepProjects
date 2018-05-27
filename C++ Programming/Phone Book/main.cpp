#include "Database.h"

int main()
{
    Database database(10);
    Subscriber tempSub;
    int opt = 0;
    char c;
    char *name = new char[10];
    int homePhone, workPhone, mobilePhone;

    cout << "Would you like to load from file ? Y/N : ";
    cin >> c;
    if (c == 'Y' || c == 'y') 
    {
        if (database.ReadDataFromFile())
        {
            cout << "Loaded data from file" << endl;
        }
    }

    while(true)
    {
        PrintLine();

        cout << "What would you like to do?" << endl
             << "Options : "                 << endl
             << "1. Add subscriber"          << endl
             << "2. Delete subscriber"       << endl
             << "3. Search subscriber"       << endl
             << "4. Show subscriber"         << endl
             << "5. Show all subscribers"    << endl
             << "6. Save data"               << endl
             << "7. Exit"                    << endl
             << "Opt : ";
        cin >> opt;
        if (1 <= opt && opt <= 7)
        {
            switch(opt)
            {
                case 1:
                    cout << "Please enter name : ";
                    cin >> name;
                    cout << "Please enter home number : ";
                    cin >> homePhone;
                    cout << "Please enter work number : ";
                    cin >> workPhone;
                    cout << "Please enter mobile number : ";
                    cin >> mobilePhone;
                    tempSub.SetName(name);
                    tempSub.SetHomePhone(homePhone); 
                    tempSub.SetWorkPhone(workPhone);
                    tempSub.SetMobilePhone(mobilePhone);
                    
                    if (database.AddSubscriber(tempSub))
                    {
                        cout << "Added" << endl;
                    }
                    else
                    {
                        cout << "Fail to add" << endl;
                    }
                    break;
                case 2:
                    cout << "Please enter index of subscriber to delete : ";
                    cin >> opt;
                    if (1 <= opt && opt <= database.GetSize())
                    {
                        if (database.DeleteSubscriber(opt - 1))
                        {
                            cout << "Deleted" << endl;
                        }
                        else
                        {
                            cout << "Fail to delete" << endl;
                        }
                    }
                    break;
                case 3:
                    cout << "Please enter name to look for : ";
                    cin >> name;

                    if (!database.SearchSubscriber(name))
                    {
                        cout << "Fail to find" << endl;
                    }
                    break;
                case 4:
                    cout << "Please enter index to show : ";
                    cin >> opt;
                    if (1 <= opt && opt <= database.GetSize())
                    {
                        PrintLine();
                        database.ShowSubscriber(opt - 1);
                    }
                    else
                    {
                        cout << "Index out of reach" << endl;
                    }
                    break;
                case 5:
                    if (database.GetSize() <= 0)
                    {
                        cout << "No subscribers" << endl;
                    }
                    else
                    {
                        database.ShowAllSubscriber();
                    }
                    break;
                case 6:
                    database.SaveDataToFile();
                    cout << "Saved data to file called Data.txt in folder called build." << endl;
                    break;
                case 7:
                    exit(0);
                    break;
            }
        }
    }
    delete []name;
    return 0;
}