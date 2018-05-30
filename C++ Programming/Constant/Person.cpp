#include "Person.h"

void Person::SetAge(int age)
{
    if (0 < age && age < 100)
    {
        this->age = age;
    }
}

//First const modifier means the returned value cannot be modified OUTSIDE of the function
//Second const modifier means there can not be modification of member variables WITHIN the function
const int &Person::GetAge() const
{
    return age;
}