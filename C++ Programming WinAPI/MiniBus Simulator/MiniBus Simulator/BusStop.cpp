#include "stdafx.h"
#include "BusStop.h"


BusStop::BusStop()
{
	SetCapacity(0);
}

BusStop::BusStop(int capacity, Time timeBetweenPassengerArrival, Time timeBetweenBusArrival)
{
	SetCapacity(capacity);
	SetIntervalPassengerArriveAt(timeBetweenPassengerArrival);
	SetIntervalBusArriveAt(timeBetweenBusArrival);
}

BusStop::~BusStop()
{
	if (passengers != NULL ) delete[] passengers;
}

void BusStop::SetCapacity(int capacity)
{
	size = 0;
	if (capacity > 0)
	{
		this->capacity = capacity;

		passengers = new Passenger[capacity];
	}
	else passengers = NULL;
}

void BusStop::SetIntervalPassengerArriveAt(Time timeBetweenPassengerArrival)
{
	this->timeBetweenPassengerArrival = timeBetweenPassengerArrival;
}

void BusStop::SetIntervalBusArriveAt(Time timeBetweenBusArrival)
{
	this->timeBetweenBusArrival = timeBetweenBusArrival;
}

bool BusStop::IsFull()
{
	return (size >= capacity);
}

int BusStop::GetAmountOfPassengers()
{
	return size;
}

void BusStop::ShiftForward(Time currentTime)
{
	Time temp = timeBetweenBusArrival + leftOverTimeFromPrevious;
	int count = 0;
	while (temp > timeBetweenPassengerArrival || temp == timeBetweenPassengerArrival)
	{
		temp = temp - timeBetweenPassengerArrival;
		count++;

		if (count == 1)
		{
			passengers[size++] = Passenger(currentTime + timeBetweenPassengerArrival - leftOverTimeFromPrevious);
		}
		else
		{
			passengers[size++] = Passenger(currentTime + timeBetweenPassengerArrival * count);
		}
	}
	leftOverTimeFromPrevious = temp;
}

Time BusStop::RemovePassengers(Time currentTime, int amount)
{
	/*Get average from passengers*/
	Time average;
	if (amount > 0)
	{
		for (int i = 0; i < amount; i++)
		{
			average = average + passengers[i].GetDurationStay(currentTime);
		}

		average = average / amount;

		for (int i = amount; i < size; i++)
		{
			passengers[i - amount] = passengers[i];
		}
		size -= amount;
	}

	return average;
}
