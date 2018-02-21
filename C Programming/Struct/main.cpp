#include <iostream>
#include <string>

using namespace std;

struct date
{
    int day;
    int month;
    int year;
};

struct fullname
{
    string firstName;
    string lastName;
};

struct human
{
    date birthday;
    fullname fullName;
    int height;
    void ShowBirthday()
    {
        cout << "Birthday is on " << birthday.day << "/" << birthday.month << "/" << birthday.year << endl;
    }
    void ShowName()
    {
        cout << "The name is " << fullName.lastName << " " << fullName.firstName << endl;
    }

};

int main()
{
    human joan;
    //Don't use cin and getline together because they cause conflict
    // cout << "Enter day of birthday : ";
    // cin >> joan.birthday.day;
    // cout << "Enter month of birthday : ";
    // cin >> joan.birthday.month;
    // cout << "Enter year of birthday : ";
    // cin >> joan.birthday.year;
    // joan.ShowBirthday();
    cout << "Enter first name : ";
    getline(cin, joan.fullName.firstName);
    cout << "Enter last name : ";
    getline(cin, joan.fullName.lastName);
    joan.ShowName();
    return 0;
}