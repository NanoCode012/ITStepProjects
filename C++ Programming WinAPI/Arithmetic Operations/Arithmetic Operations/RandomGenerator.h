#pragma once
#include <stdlib.h>
#include <time.h>

class RandomGenerator
{
public:
	static bool hasSetSeed;

	static int SetSeed();

	static int GetRandomNumber();

	static int GetRandomNumber(int max);

	static int GetRandomNumber(int min, int max);
};



