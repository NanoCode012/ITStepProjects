#include <stdlib.h>
#include <time.h>

bool hasSetSeed = false;

int SetSeed(){
    srand(time(NULL));
    return 0;
}

int GetRandomNumber(){
    if (!hasSetSeed) {
        SetSeed();
        hasSetSeed = true;
    }
    return rand();
}

int GetRandomNumber(int max){
    if (max <= 0) return -1;
    else return GetRandomNumber() % (max + 1);
}

int GetRandomNumber(int min, int max){
    if (min < 0 || max <= 0) return -1;
    else return min + GetRandomNumber(max - min);
}