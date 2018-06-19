#pragma once

#include <iostream>

class Date
{
private: 
    int day;
    int month;
    int year;
public:
    Date(int dd = 0, int mm = 0, int yyyy = 0);

    int operator - (const Date &other);

    Date operator + (int daysToAdd);
    void operator = (const Date &other);
    void operator += (int daysToAdd);

    void Output();

    int GetDay();
    int GetMonth();
    int GetYear();
};