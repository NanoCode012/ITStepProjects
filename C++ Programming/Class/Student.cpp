#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    char *name;
    string dob, city, country, school, schoolCity;
    int phoneNumber, trainingGroupNumber;

public:
    Student(const char *name, string dob, string city, string country, string school, string schoolCity, int phoneNumber, int trainingGroupNumber)
    {
        this->name = new char[strlen(name) + 1];//+1 for terminator
        strcpy(this->name, name);
        this->dob = dob;
        this->city = city;
        this->country = country;
        this->school = school;
        this->schoolCity = schoolCity;
        this->phoneNumber = phoneNumber;
        this->trainingGroupNumber = trainingGroupNumber;
    }

    ~Student()
    {
        cout << "Instance named " << name << " is being destroyed" << endl;
        delete[] name;
    }

    void Show()
    {
        cout << "name : " << name << endl
             << "dob : " << dob << endl
             << "city : " << city << endl
             << "country : " << country << endl
             << "school : " << school << endl
             << "schoolCity : " << schoolCity << endl
             << "phoneNumebr : " << phoneNumber << endl
             << "trainingGroupNumber : " << trainingGroupNumber << endl;
    }
};