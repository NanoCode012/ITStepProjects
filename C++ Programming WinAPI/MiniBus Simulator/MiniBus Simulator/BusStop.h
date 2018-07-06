#pragma once
#include "Time.h"
#include "Passenger.h"

class BusStop
{
	int size;
	int capacity;
	
	Time timeBetweenPassengerArrival;
	Time timeBetweenBusArrival;
	Time leftOverTimeFromPrevious;

	Passenger *passengers;
public:
	BusStop();
	BusStop(int capacity, Time timeBetweenPassengerArrival ,Time timeBetweenBusArrival);
	~BusStop();

	void SetCapacity(int capacity);
	void SetIntervalPassengerArriveAt(Time timeBetweenPassengerArrival);
	void SetIntervalBusArriveAt(Time timeBetweenBusArrival);

	bool IsFull();
	int GetAmountOfPassengers();

	void ShiftForward(Time currentTime);
	Time RemovePassengers(Time currentTime, int amount);
};

