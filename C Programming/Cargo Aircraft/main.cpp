#include <iostream>

using namespace std;

int main(){
    //Declare
    int capacity = 300;
    int fuelToB = 0;
    int fuelToC = 0;
    int cargoWeight = 0;

    int distToB = 0;
    int distToC = 0;
    int distAbleToFly = 0;

    int consumption = -1;//-1 for default/error. 0 for cannot fly. >0 for can fly
    int fuelNeedToRefill = 0;

    //Input

    cout << "Please enter how heavy the cargo is (kg): ";
    cin >> cargoWeight;
    cout << "You are at A" << endl;

    cout << "Distance to B from A: ";
    cin >> distToB;

    cout << "Distance to C from B: ";
    cin >> distToC;

    //Logic
    if (cargoWeight > 2000){
        consumption = 0;
    }else if (cargoWeight > 1500){
        consumption = 9;
    }else if (cargoWeight > 1000){
        consumption = 7;
    }else if (cargoWeight > 500){
        consumption = 4;
    }else if (cargoWeight > 0){
        consumption = 1;
    }
    fuelToB = distToB * consumption;
    fuelToC = distToC * consumption;
    fuelNeedToRefill = fuelToC - (capacity - fuelToB);

    //Output
    if (fuelToB > capacity && fuelToC > capacity){
        cout << "Cannot proceed with flight. Capacity not enough for both flights." << endl;
    }else if (fuelToB <= capacity && fuelToC > capacity){
        cout << "Can only travel from A to B, not from B to C" << endl;
    }else if (fuelToB > capacity && fuelToC <= capacity){
        cout << "Can only travel from B to C, not from A to B" << endl;
    }else if (fuelToB == 0 && fuelToC == 0){
        cout << "Cargo overloaded. Flight aborted." << endl;
    }else if (fuelToB < 0 && fuelToC < 0){
        cout << "An error occurred somewhere. Unaccounted for logic. "
             << "(Possibly negative distances)" << endl;
    }else if (fuelToB <= capacity && fuelToC <= capacity){
        cout << "We need " << fuelToB << "L from A to B." << endl;
        if (fuelNeedToRefill <= 0){
            cout << "If we started with 300L, "
                 << "we can fly directly towards to C, without refilling." << endl;
        }else{
            cout << "We need to refill " << fuelNeedToRefill << "L at B." << endl;
        }
        cout << "We need " << fuelToC << "L from B to C." << endl;
    }
}