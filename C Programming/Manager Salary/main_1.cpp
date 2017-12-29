#include <iostream>

using namespace std;

int main(){
    //Declare
    int salary = 200;
    float managerOneSalary = 0;
    float managerTwoSalary = 0;
    float managerThreeSalary = 0;

    //Input
    cout << "Sales of Manager No 1: ";
    cin >> managerOneSalary;
    cout << "Sales of Manager No 2: ";
    cin >> managerTwoSalary;
    cout << "Sales of Manager No 3: ";
    cin >> managerThreeSalary;

    if (managerOneSalary > 1000){
        managerOneSalary *= 0.08;
    }else if (managerOneSalary > 500){
        managerOneSalary *= 0.05;
    }else if (managerOneSalary > 0){
        managerOneSalary *= 0.03;
    }
    managerOneSalary += salary;

    if (managerTwoSalary > 1000){
        managerTwoSalary *= 0.08;
    }else if (managerTwoSalary > 500){
        managerTwoSalary *= 0.05;
    }else if (managerTwoSalary > 0){
        managerTwoSalary *= 0.03;
    }
    managerTwoSalary += salary;

    if (managerThreeSalary > 1000){
        managerThreeSalary *= 0.08;
    }else if (managerThreeSalary > 500){
        managerThreeSalary *= 0.05;
    }else if (managerThreeSalary > 0){
        managerThreeSalary *= 0.03;
    }
    managerThreeSalary += salary;

    cout << "M1: " << managerOneSalary << endl;
    cout << "M2: " << managerTwoSalary << endl;
    cout << "M3: " << managerThreeSalary << endl;

    if (managerOneSalary > managerTwoSalary){
        if (managerOneSalary > managerThreeSalary){
            managerOneSalary += 200;
            cout << "Best is M1 rewarded with " << managerOneSalary << endl;
        }else{
            managerThreeSalary += 200;
            cout << "Best is M3 rewarded with " << managerThreeSalary << endl;
        }
    }else{
        if (managerTwoSalary > managerThreeSalary){
            managerTwoSalary += 200;
            cout << "Best is M2 rewarded with " << managerTwoSalary << endl;
        }else {
            managerThreeSalary += 200;
            cout << "Best is M3 rewarded with " << managerThreeSalary << endl;
        }
    }
    

    return 0;
}