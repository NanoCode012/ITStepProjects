#include "stdafx.h"
#include "Date.h"

using namespace std;

int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int Date::GetLeftoverDaysInBetweenTwoMonths(int d0, int m0, int y0, int d1, int m1, int y1)
{
	int sum = 0;
	if (m0 == m1 && y0 == y1) {
		sum += d1 - d0;
	}
	else {
		sum += months[m0 - 1] - d0;
		sum += d1;
		
		if (IsLeapYear(m0, y0)) sum++;
	}
	return sum;
}

int Date::GetDaysInBetweenConsecutiveMonths(int m0, int y0, int m1, int y1)
{
	int sum = 0;
	int monthsToRun = 0;
	if (y0 == y1)
	{
		monthsToRun = m1 - m0 - 1;
	}
	else
	{
		monthsToRun = 12 - m0 + m1 - 1;
	}

	int tempMonth = m0;
	while (monthsToRun-- > 0)
	{
		sum += months[tempMonth % 12];
		if (tempMonth % 12 == 1)
		{
			if (monthsToRun >= 11) {
				if (IsLeapYear(2 , y0)) sum++;
			}
			else {
				if (IsLeapYear(2, y1)) sum++;
			}
		}
		tempMonth++;
	}
	return sum;
}

bool Date::IsLeapYear(int m0, int y0)
{
	return (m0 == 2 && y0 % 4 == 0 && !(y0 % 100 == 0 && y0 % 400 != 0));
}

Date::Date(int dd, int mm, int yyyy)
{
	//Check if values inputted are zero or below
	//and set it to default values
	if (dd <= 0) dd = 1;
	if (mm <= 0) mm = 1;
	if (yyyy <= 0) yyyy = 1970;

	//Check if days inputted is higher than max days in month
	//and set it to the month's max value
	if (mm == 2)
	{
		if ((IsLeapYear(mm, yyyy) && dd > 29))
		{
			dd = 29;
		}
		else if (!IsLeapYear(mm, yyyy) && dd > 28)
		{
			dd = 28;
		}
	}
	else if (months[mm - 1] < dd)
	{
		dd = months[mm - 1];
	}
	
	this->day = dd;
	this->month = mm;
	this->year = yyyy;
}

int Date::operator - (const Date &other)
{
	int d0 = other.day;
	int m0 = other.month;
	int y0 = other.year;
	int d1 = this->day;
	int m1 = this->month;
	int y1 = this->year;

	int sumDays = 0;
	int diffYear = y1 - y0 - 1;

	sumDays += GetLeftoverDaysInBetweenTwoMonths(d0, m0, y0, d1, m1, y1);
	sumDays += GetDaysInBetweenConsecutiveMonths(m0, y0, m1, y1);

	//Calculate days of year(s) in between y0 and y1 if exists
	if (diffYear > 0) {
		sumDays += diffYear * 365;//Increase days by year
		for (int year = y0 + 1; year < y1; year++) {//Check for leap years in between
			if (IsLeapYear(2, year)) sumDays++;
		}
	}
	return sumDays;
}

Date Date::operator + (int daysToAdd)
{
	int d1 = this->day;
	int m1 = this->month;
	int y1 = this->year;

	int daysLeftInTheMonth = 0;
	while (daysToAdd > 0)
	{
		daysLeftInTheMonth = (months[m1 - 1] - d1);
		if (IsLeapYear(m1, y1) && daysToAdd > (daysLeftInTheMonth + 1))//Leap year
		{
			daysToAdd -= (daysLeftInTheMonth + 2);
			d1 = 1;
			m1++;
		}
		else if (daysToAdd > daysLeftInTheMonth)//Cross month
		{
			daysToAdd -= (daysLeftInTheMonth + 1);
			d1 = 1;
			if (m1 == 12)
			{
				y1++;
				m1 = 1;
			}
			else m1++;
		}
		else//Same month
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
