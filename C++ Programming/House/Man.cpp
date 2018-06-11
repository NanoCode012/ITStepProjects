#include "Man.h"

using namespace std;

void Man::SetName(const char* name)
{
    if (name != NULL)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    else
    {
        this->name = NULL;
    }
}

void Man::SetAge(int age)
{
    if (age > 0)
    {
        this->age = age;
    }
}

Man::Man()
{
    SetName(NULL);
    SetAge(1);
}

Man::Man(const char* name, int age)
{
    SetName(name);
    SetAge(age);
}

Man::Man(const Man &other) 
{
    Copy(other);
}

Man::~Man()
{
	if (name != NULL)
	{
		//cout << "Man is being deleted" << endl;
		delete[] name;
	}
	else
	{
		cout << "Man's name is already NULL." << endl;
	}
}

void Man::operator=(const Man &other)
{
    Copy(other);
}

void Man::Copy(const Man &other)
{
    this->SetName(other.name);
    this->SetAge(other.age);
}

char* Man::GetName()
{
    return name;
}

int Man::GetAge()
{
    return age;
}