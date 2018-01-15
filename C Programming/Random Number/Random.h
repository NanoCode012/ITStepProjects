#include <stdlib.h>
#include <time.h>

int GetRandomNumber(int seed = 1){
    if (seed == 0) seed = -1;
    srand(seed * time(NULL));
    return rand();
}

int GetRandomNumber(int max){
    if (max <= 0) return -1;
    else return GetRandomNumber(max) % (max + 1);
}

int GetRandomNumber(int min, int max){
    if (min < 0 || max <= 0) return -1;
    else return min + GetRandomNumber(max - min);
}