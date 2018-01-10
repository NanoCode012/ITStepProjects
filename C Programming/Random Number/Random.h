#include <stdlib.h>
#include <time.h>

int GetRandomNumber(){
    srand(time(NULL));
    return rand();
}

int GetRandomNumber(int max){
    return GetRandomNumber() % (max + 1);
}

int GetRandomNumber(int min, int max){
    return min + GetRandomNumber(max - min);
}