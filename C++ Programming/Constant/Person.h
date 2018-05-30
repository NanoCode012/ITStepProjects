#pragma once

class Person
{
private:
    int age;
public:
    void SetAge(int age);
    const int &GetAge() const;
};