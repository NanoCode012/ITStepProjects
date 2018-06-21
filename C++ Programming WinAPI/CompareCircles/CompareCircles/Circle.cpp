#include "stdafx.h"
#include "Circle.h"

Circle::Circle(int x, int y, int r)
{
	SetX(x);
	SetY(y);
	SetR(r);
}

Circle::~Circle()
{
}

bool Circle::operator==(const Circle & other)
{
	return (this->r == other.r);
}

bool Circle::operator>(const Circle & other)
{
	return (this->r > other.r);
}

void Circle::operator++(int k)
{
	r++;
}

void Circle::operator--(int k)
{
	r--;
}

int Circle::GetX()
{
	return x;
}

int Circle::GetY()
{
	return y;
}

int Circle::GetR()
{
	return r;
}

void Circle::SetX(int x)
{
	this->x = x;
}

void Circle::SetY(int y)
{
	this->y = y;
}

void Circle::SetR(int r)
{
	this->r = r;
}

void Draw(Circle circle, HDC hdc)
{
	Ellipse(hdc, circle.GetX() - circle.GetR(), circle.GetY() - circle.GetR(), circle.GetX() + circle.GetR(), circle.GetY() + circle.GetR());
}
