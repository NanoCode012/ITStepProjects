#include "../Leaderboard/array.h"

int LinearSearch(int arr[], int key){
    int count = Count(arr);
    int result = -1;
    for (int i = 0; i < count; i++){
        if (arr[i] == key) result = i;
    }
    return result;
}