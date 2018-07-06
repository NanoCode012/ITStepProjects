#include "stdafx.h"
#include "Bus.h"

Bus::Bus(int capacity, int maxStop)
{
	SetCapacity(capacity);
	
	SetMaxStops(maxStop);

	movingRight = true;

	leftBase = false;
}

void Bus::SetCapacity(int capacity)
{
	size = 0;
	this->capacity = capacity;
}

void Bus::SetMaxStops(int maxStop)
{
	currentStop = 0;
	this->maxStop = maxStop;
}

void Bus::AddPassengers(int amount)
{
	size += amount;
}

int Bus::GetFreeSeats()
{
	return (capacity - size);
}

void Bus::RandomizeFreeSeats()
{
	if (currentStop == 1 || currentStop == maxStop)
	{
		size = 0;
	}
	else
	{
		if (size > 0)
		{
			size -= RandomGenerator::GetRandomNumber(size);
		}
	}
}

void Bus::MoveToNextStop()
{
	RandomizeFreeSeats();

	if (movingRight) currentStop++;
	else currentStop--;
	
	if (leftBase)
	{
		if (currentStop <= 1 || currentStop >= maxStop)
		{
			movingRight = !movingRight;
		}
	}
	else
	{
		leftBase = true;
	}
}

int Bus::GetStopNumber()
{
	return currentStop;
}
