#include "stdafx.h"
#include "RandomGenerator.h"

bool RandomGenerator::hasSetSeed = false;

int RandomGenerator::SetSeed() {
	srand(time(NULL));
	return 0;
}

int RandomGenerator::GetRandomNumber() {
	if (!hasSetSeed) {
		SetSeed();
		hasSetSeed = true;
	}
	return rand();
}

int RandomGenerator::GetRandomNumber(int max) {
	if (max < 0) return -1;
	else return GetRandomNumber() % (max + 1);
}

int RandomGenerator::GetRandomNumber(int min, int max) {
	if (min < 0 || max < 0) return -1;
	else return min + GetRandomNumber(max - min);
}