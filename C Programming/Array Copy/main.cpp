#include <iostream>

using namespace std;

int main(){
    int count = 0;
    int arrayOne[] = {2,7,-5,0,1};
    int arrayTwo[] = {0,-9,13,21,-5};
    int arrayThree[10];
    for(int i = 0; i < 5; i++){
        if (arrayOne[i] > 0) {
            arrayThree[count] = arrayOne[i];
            count++;
        }
        if (arrayTwo[i] > 0) {
            arrayThree[count] = arrayTwo[i];
            count++;
        }
    }
    for(int i = 0; i < 5; i++){
        if (arrayOne[i] == 0) {
            arrayThree[count] = arrayOne[i];
            count++;
        }
        if (arrayTwo[i] == 0) {
            arrayThree[count] = arrayTwo[i];
            count++;
        }
    }
    for(int i = 0; i < 5; i++){
        if (arrayOne[i] < 0) {
            arrayThree[count] = arrayOne[i];
            count++;
        }
        if (arrayTwo[i] < 0) {
            arrayThree[count] = arrayTwo[i];
            count++;
        }
    }
    for(int i = 0; i < count; i++){
        cout << arrayThree[i] << " " << endl;
    }
    
    return 0;
}