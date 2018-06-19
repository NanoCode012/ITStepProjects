#include "Date.h"

using namespace std;

Date::Date(int dd, int mm, int yyyy)
{
    this->day = dd;
    this->month = mm;
    this->year = yyyy;
}

int Date::operator - (const Date &other)
{
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    int d0 = other.day;
    int m0 = other.month;
    int y0 = other.year;
    int d1 = this->day;
    int m1 = this->month;
    int y1 = this->year;


    int sumDays = 0;
    int diffYear = y1 - y0 - 1;
    int monthsToRun;
    
    
    if (diffYear > 0){//dif 2 or more year apart
        // if (m0 != m1) monthsToRun = 12 - m0 + m1 - 1;
        monthsToRun = 12 - m0 + m1 - 1;
        sumDays += month[m0 - 1] - d0;
        sumDays += d1;
        sumDays += diffYear * 365;//Increase days by year
        for(int year = y0 + 1; year < y1; year++){//Only if there are years in between
            if(year % 4 == 0 && year % 100 != 0) sumDays++;
        }
        int tempMonth = m0;
        // if (tempMonth == 2) sumDays++;//if the start month is 2
        while(monthsToRun-- > 0)
        {
            sumDays += month[tempMonth % 12];
            if (tempMonth % 12 == 1)
            {
                if (monthsToRun >= 12){
                    if (y0 % 4 == 0 && y0 % 100 != 0) sumDays++;
                }else {
                    if (y1 % 4 == 0 && y1 % 100 != 0) sumDays++;
                }
            }
            tempMonth++;
        }
    }else if(diffYear < 0){//same year
        if (m0 == m1){
            monthsToRun = 0;
            sumDays += d1 - d0;
        }else {
            sumDays += month[m0 - 1] - d0;
            sumDays += d1;
            for(int i = m0; i < m1 - 1; i++){
                if(m0 == 1 && y0 % 4 == 0 && y0 % 100 != 0) sumDays++;
                sumDays += month[i];
            }
        }
    }else {//year after year each other
        sumDays += month[m0 - 1] - d0;
        sumDays += d1;
        monthsToRun = 12 - m0 + m1 - 1;
        int tempMonth = m0;
        while(monthsToRun-- > 0)
        {
            sumDays += month[tempMonth % 12];
            if (tempMonth == 1)
            {
                if (monthsToRun >= 12){
                    if (y0 % 4 == 0 && y0 % 100 != 0) sumDays++;
                }else {
                    if (y1 % 4 == 0 && y1 % 100 != 0) sumDays++;
                }
            }
            tempMonth++;
        }
    }
    return sumDays;
}

Date Date::operator+ (int daysToAdd)
{
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int d1 = this->day;
    int m1 = this->month;
    int y1 = this->year;

    while(daysToAdd > 0)
    {
        if (daysToAdd > (month[m1 - 1] - d1))
        {
			daysToAdd -= (month[m1 - 1] - d1 + 1);
			d1 = 1;
            if (m1 == 12)
            {
                y1++;
                m1 = 1;
            }
            else
            {
                m1++;
            }
        }
        else
        {
            d1 += daysToAdd;
			daysToAdd = 0;
        }
    }
    return Date(d1, m1, y1);
}

void Date::operator = (const Date &other)
{
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

void Date::operator+= (int daysToAdd)
{
    Date temp(this->day, this->month, this->year);
    temp = temp + daysToAdd;

    this->day = temp.day;
    this->month = temp.month;
    this->year = temp.year;
}

void Date::Output()
{
    cout << day << "-" << month << "-" << year << endl;
}

int Date::GetDay()
{
    return day;
}

int Date::GetMonth()
{
    return month;
}

int Date::GetYear()
{
    return year;
}
    