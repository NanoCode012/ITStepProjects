#pragma once
#include "RandomGenerator.h"

class Bus
{
	int size;
	int capacity;
	
	int currentStop;
	int maxStop;

	bool movingRight;
	
	bool leftBase;
public:
	Bus(int capacity = 20, int maxStop = 5);

	void SetCapacity(int capacity);
	void SetMaxStops(int maxStop);

	void AddPassengers(int amount);

	int GetFreeSeats();
	void RandomizeFreeSeats();

	void MoveToNextStop();

	int GetStopNumber();
};

