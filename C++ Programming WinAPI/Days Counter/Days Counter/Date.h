#pragma once

#include <iostream>

class Date
{
private:
	int day;
	int month;
	int year;

	int GetLeftoverDaysInBetweenTwoMonths(int d0, int m0, int y0, int d1, int m1, int y1);
	int GetDaysInBetweenConsecutiveMonths(int m0, int y0, int m1, int y1);
	bool IsLeapYear(int m0, int y0);
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