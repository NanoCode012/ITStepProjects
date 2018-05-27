#include "Database.h"

using namespace std;

bool Database::IsFull()
{
    return (size >= capacity);
}

Database::Database(int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    subscribers = new Subscriber[capacity];
}
Database::~Database()
{
}

bool Database::AddSubscriber(Subscriber subscriber)
{
    bool added = false;
    if (size < capacity)
    {
        subscribers[size].SetName(subscriber.GetName());
        subscribers[size].SetHomePhone(subscriber.GetHomePhone());
        subscribers[size].SetWorkPhone(subscriber.GetWorkPhone());
        subscribers[size].SetMobilePhone(subscriber.GetMobilePhone());
        
        size++;
        added = true;
    }    
    return (added);
}
bool Database::DeleteSubscriber(int indexOfSubscriber)
{
    bool deleted = true;
    if (indexOfSubscriber == 0) size = 0;
    else if (indexOfSubscriber == size - 1) size--;
    else if (indexOfSubscriber < size - 1)
    {
        subscribers[indexOfSubscriber].SetName(subscribers[size - 1].GetName());
        subscribers[indexOfSubscriber].SetHomePhone(subscribers[size - 1].GetHomePhone());
        subscribers[indexOfSubscriber].SetWorkPhone(subscribers[size - 1].GetWorkPhone());
        subscribers[indexOfSubscriber].SetMobilePhone(subscribers[size - 1].GetMobilePhone());
        size--;
    }
    else deleted = false;
    
    return (deleted);
}

bool Database::SearchSubscriber(const char * name)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(subscribers[i].GetName(), name) == 0)
        {
            found = true;
            ShowSubscriber(i);
        }
    }

    return found;
}

void Database::ShowSubscriber(int index)
{
    cout << "Index : " << index + 1 << endl
         << "Name : " << subscribers[index].GetName() << endl
         << "Home Num : " << subscribers[index].GetHomePhone() << endl
         << "Work Num : " << subscribers[index].GetWorkPhone() << endl
         << "Mobile Num : " << subscribers[index].GetMobilePhone() << endl;
}
void Database::ShowAllSubscriber()
{
    if (size > 0)
    {
        PrintLine();
        for (int i = 0; i < size; i++)
        {
            ShowSubscriber(i);
            PrintLine();
        }
    }
}

void Database::SaveDataToFile(const char * path)
{
    ofstream writeStream(path);
    if (writeStream)
    {
        writeStream << size << " " << capacity << endl;
        for(int i = 0; i < size; i++)
        {
            writeStream << subscribers[i].GetName() << " " << subscribers[i].GetHomePhone() << " "
                        << subscribers[i].GetWorkPhone() << " " << subscribers[i].GetMobilePhone() << " "
                        << endl;
        }
    }

    writeStream.close();
}
bool Database::ReadDataFromFile(const char * path)
{
    ifstream readStream(path);
    bool canRead = readStream.is_open();
    if (canRead)
    {
        readStream >> size >> capacity;

        char *name = new char[10];
        int homePhone, workPhone, mobilePhone;

        for(int i = 0; i < size; i++)
        {
            readStream >> name;
            readStream >> homePhone >> workPhone >> mobilePhone;

            subscribers[i].SetName(name);
            subscribers[i].SetHomePhone(homePhone);
            subscribers[i].SetWorkPhone(workPhone);
            subscribers[i].SetMobilePhone(mobilePhone);
        }
        delete []name;
    }

    readStream.close();
    return (canRead);
}

int Database::GetSize()
{
    return size;
}