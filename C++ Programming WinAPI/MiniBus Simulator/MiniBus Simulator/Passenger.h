#pragma once
#include "Time.h"

class Passenger
{
	Time timeArrived;
	Time timeDeparture;
	
public:
	Passenger();
	Passenger(Time timeReached);
	Passenger(const Passenger &other);

	void operator = (const Passenger &other);

	void SetTimeArrived(Time timeReached);

	Time GetDurationStay(Time timeLeft);
};

