#include "stdafx.h"
#include "Passenger.h"

Passenger::Passenger()
{
}

Passenger::Passenger(Time timeReached)
{
	SetTimeArrived(timeReached);
}

Passenger::Passenger(const Passenger & other)
{
	this->timeArrived = other.timeArrived;
	this->timeDeparture = other.timeDeparture;
}

void Passenger::operator=(const Passenger & other)
{
	this->timeArrived = other.timeArrived;
	this->timeDeparture = other.timeDeparture;
}

void Passenger::SetTimeArrived(Time timeReached)
{
	this->timeArrived = timeReached;
}

Time Passenger::GetDurationStay(Time timeLeft)
{
	return (timeLeft - timeArrived);
}
