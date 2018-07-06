#include "stdafx.h"
#include "Time.h"

Time::Time(int hh, int mm, bool isAmericanTime, bool isAM)
{
	SetType(isAmericanTime);
	SetAMOrPM(isAM);

	SetHour(hh);
	SetMin(mm);

}

Time::Time(const Time & other)
{
	this->hh = other.hh;
	this->mm = other.mm;
	this->isAM = other.isAM;
	this->isAmericanTime = other.isAmericanTime;
}

void Time::SetHour(int h)
{
	if (0 <= h && h <= (isAmericanTime ? 12 : 23)) this->hh = h;
	else this->hh = 0;
}

void Time::SetMin(int m)
{
	if (0 <= m && m <= 59) this->mm = m;
	else this->mm = 0;
}

void Time::SetType(bool isAmericanTime)
{
	this->isAmericanTime = isAmericanTime;
}

void Time::SetAMOrPM(bool isAM)
{
	this->isAM = isAM;
}

int Time::GetHour()
{
	return hh;
}

int Time::GetMin()
{
	return mm;
}

bool Time::IsAmericanTime()
{
	return isAmericanTime;
}

bool Time::IsAM()
{
	return isAM;
}

Time Time::operator+(const Time & other)
{
	int h = this->hh + other.hh;
	int m = this->mm + other.mm;
	if (m >= 60)
	{
		h++;
		m %= 60;
	}
	if (h >= 24)
	{
		h %= 24;
	}
	return Time(h, m);
}

Time Time::operator-(const Time & other)
{
	int h = this->hh - other.hh;
	int m = this->mm - other.mm;
	if (m < 0)
	{
		h--;
		m %= 60;
	}
	if (h < 0)
	{
		h %= 24;
	}
	return Time(h, m);
}

Time Time::operator/(int num)
{
	int h = this->hh;
	int m = this->mm;
	m += h * 60;

	m /= num;
	return Time(m / 60, m % 60);
}

Time Time::operator*(int num)
{
	int h = this->hh;
	int m = this->mm;
	m += h * 60;

	m *= num;
	return Time(m / 60, m % 60);
}

bool Time::operator>(const Time & other)
{
	if (this->hh > other.hh) return true;
	else if (this->hh == other.hh)
	{
		if (this->mm > other.mm) return true;
		else return false;
	}
	return false;
}

bool Time::operator==(const Time & other)
{
	return (this->hh == other.hh && this->mm == other.mm
		&& this->isAmericanTime == other.isAmericanTime && this->isAM == other.isAM);
}

void Time::operator=(const Time & other)
{
	this->hh = other.hh;
	this->mm = other.mm;
	this->isAM = other.isAM;
	this->isAmericanTime = other.isAmericanTime;
}

Time Convert(Time t, bool fromAmericanTimeToGMT)
{
	int tempH = t.GetHour();
	int tempM = t.GetMin();
	bool type = t.IsAmericanTime();
	bool isAM = t.IsAM();

	if (fromAmericanTimeToGMT)
	{
		if (t.IsAM())
		{
			if (tempH == 12) tempH = 0;
		}
		else
		{
			if (tempH != 12) tempH += 12;
		}
		type = false;
		isAM = true;
	}
	else
	{
		if (0 <= tempH && tempH <= 11)
		{
			isAM = true;

		}
		else if (tempH == 12)
		{
			isAM = false;
		}
		else if (13 <= tempH && tempH <= 23)
		{
			isAM = false;
			tempH -= 12;
		}
		else if (tempH == 24)
		{
			isAM = true;
			tempH = 0;
		}
		type = true;
	}
	return Time(tempH, tempM, type, isAM);
}
