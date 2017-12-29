#include <iostream>

using namespace std;

int main(){
    //Declare
    int baseSalary = 200;
    float input = 0;
    float managerOneSalary = 0;
    float managerTwoSalary = 0;
    float managerThreeSalary = 0;

    int i = 0;
    int id = 0;
    int maxSales = 0;

    //Logic
AppStart:
    i++;
    //Input
    cout << "Sales of Manager No " << i << ": ";
    cin >> input;

    //ApplyForm
    if (input > 1000){
        input *= 0.08;
    }else if (input > 500){
        input *= 0.05;
    }else if (input > 0){
        input *= 0.03;
    }
    input += baseSalary;

    //Find largest
    if (input > maxSales){
        maxSales = input;
        id = i;
    }

    //Output individual manager
    cout << "M" << i << ": " << input << endl;
    if (i == 1){
        managerOneSalary = input;
        goto AppStart;
    }else if (i == 2){
        managerTwoSalary = input;
        goto AppStart;
    }else if (i == 3){
        managerThreeSalary = input;
    }

    //Output best manager
    if (id == 1){
        cout << "Best is M" << id << " rewarded with " << managerOneSalary + 200<< endl;
    }else if (id == 2){
        cout << "Best is M" << id << " rewarded with " << managerTwoSalary + 200<< endl;
    }else if (id == 3){
        cout << "Best is M" << id << " rewarded with " << managerThreeSalary + 200<< endl;
    }

    return 0;
}